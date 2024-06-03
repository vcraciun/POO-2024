#include <windows.h>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

#define ASM_RETURN 0xC3
#define CELL_SIZE 0x1000

enum Permisions
{
    ERR=-1, R, RW, RX, RWX
};

int main();

class MemoryTraversal
{
    map<size_t, pair<int, Permisions>> cells;

    static void Traversal(MemoryTraversal* m);
    static Permisions CheckAccess(size_t addr);
public:
    MemoryTraversal();
    void print();
};

void MemoryTraversal::print()
{
    int sum = 0;
    char access[4][4] = {"R", "RW", "RE", "RWE"};
    size_t stack_addr = (size_t)&sum;
    size_t code_addr = (size_t)&main;
    size_t env_addr = (size_t)__readfsdword(0x18);
    for (auto &cell : cells)
    {
        sum += cell.second.first; 
        if (stack_addr >= cell.first && stack_addr < cell.first + cell.second.first)
            printf("addr:%08X size:%08X access:%s [STACK]\n", cell.first, cell.second.first, access[cell.second.second]);
        else
            if (code_addr >= cell.first && code_addr < cell.first + cell.second.first)
                printf("addr:%08X size:%08X access:%s [THIS_APP_CODE]\n", cell.first, cell.second.first, access[cell.second.second]);
            else
                if (env_addr >= cell.first && env_addr < cell.first + cell.second.first)
                    printf("addr:%08X size:%08X access:%s [ENVIRONMENT]\n", cell.first, cell.second.first, access[cell.second.second]);
                else
                    if (cell.second.second == RX)
                        printf("addr:%08X size:%08X access:%s [WINDOWS_LIBRARY]\n", cell.first, cell.second.first, access[cell.second.second]);
                    else
                        printf("addr:%08X size:%08X access:%s\n", cell.first, cell.second.first, access[cell.second.second]);
    }
    printf("Total mem: %d.%d MB\n", sum / 0x100000, sum % 0x100000);
}

Permisions MemoryTraversal::CheckAccess(size_t addr)
{
    char read = 0;
    char exec = -1;
    char writ = -1;
    unsigned char saved_byte = 0;

    __try {
        saved_byte = *(unsigned char*)addr;
        read = 1;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return ERR;
    }

    for (size_t start = addr; start < addr + CELL_SIZE; start++)
    {   
        if (*(unsigned char*)start == ASM_RETURN)
        {
            __try {
                ((void(*)())start)();
                exec = 1;
            }
            __except (EXCEPTION_EXECUTE_HANDLER){
                exec = 0;
            }
            break;
        }
    }

    __try {
        *(unsigned char*)addr = saved_byte;
        writ = 1;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        writ = 0;
    }

    char result = (writ << 1) | exec;

    switch (result)
    {
        case 3: return RWX;
        case 2: return RW;
        case 1: return RX;
    }

    return R;
}

void MemoryTraversal::Traversal(MemoryTraversal* m)
{    
    pair<size_t, size_t> last_cell = { 0, 0 };
    Permisions acc = ERR;
    Permisions last_acc = ERR;
    double percent;
    double time;
    LARGE_INTEGER start;
    LARGE_INTEGER stop;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    unsigned long long max_val = 0x80000000;
    double total_compute_time = 0;

    for (size_t s = 0x00100000; s < 0x7fffffff; s += CELL_SIZE)
    {
        QueryPerformanceCounter(&stop);
        time = (stop.QuadPart - start.QuadPart) / (double)freq.QuadPart;
        percent = (double)s / (max_val / 100);
        if (s < 0x08000000)
            printf("\rScanning address: ... %08X : %.2lf %%, time: %.2lf/? s", s, percent, time);
        else
        {
            if (!total_compute_time)
                total_compute_time = time * 16;
            printf("\rScanning address: ... %08X : %.2lf %%, time: %.2lf/%.2lf s", s, percent, time, total_compute_time);
        }
        //checkk memory access rigths
        acc = CheckAccess(s);
        //if invalid memory or different access rights
        if (acc == ERR || ((acc != last_acc) && (last_acc != ERR)))
        {
            //if previous cell was valid, then register the working cell
            if (last_cell.first && last_cell.second)
            {
                m->cells[last_cell.first] = { last_cell.second, last_acc };
                if (acc == ERR)
                    last_cell = { 0,0 };
                else
                    last_cell = { s, CELL_SIZE };
            }
        }
        else
        {
            //if first attempt, initialize the working cell
            if (!last_cell.first && !last_cell.second)
                last_cell = { s, CELL_SIZE };
            //otherwise update the working cell
            else            
                last_cell = { last_cell.first, last_cell.second + CELL_SIZE };            
        }

        //preserve the current access, for next computation            
        last_acc = acc;
    }
    printf("\n");
}

MemoryTraversal::MemoryTraversal()
{
    Traversal(this);
}

int main()
{
    MemoryTraversal m;
    m.print();
}