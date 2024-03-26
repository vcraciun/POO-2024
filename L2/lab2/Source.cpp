#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header1.h"
#include "header2.h"
#include "common.h"

int dummy = 50;

char* computation(int nr) {
    char* result = new char[20];
    memset(result, 0, 20);
    int i = 0;
    while (nr) {
        int c = nr % 10;
        result[i] = c + '0';
        nr /= 10;
        i++;
    }
    return result;
}

int myf(int* m_addr) {
    static int m = 100;
    *m_addr = (int)&m;
    return m++;
}

/*typedef int (*func_type)(int, int);

int f1(int a, int b) {
    return a + b;
}
int f2(int a, int b) {
    return a - b;
}
int f3(int a, int b) {
    return a * b;
}
int f4(int a, int b) {
    return a / b;
}*/

extern int my_extra_f(void);

int main(void) {
    int x = myfa(5, 3);
    int y = myfb(5, 3);
    printf("x = %d, y = %d\n", x, y);

    int res = my_extra_f();
    printf("res = %d\n", res);

    /*int static_addr = 0;
    int a = myf(&static_addr);
    *(int*)static_addr = 1000;
    int b = myf(&static_addr);
    printf("static_addr = %08X\n", static_addr);
    printf("a = %d, b = %d\n", a, b);*/

    /*char* data = computation(5201);
    char* data2 = computation(4444);
    printf("data = %s | %s\n", data, data2);*/
    
    /*func_type myf[4] = {f1, f2, f3, f4};
    char operators[4] = {'+', '-', '*', '/'};
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        int a = rand() % 100;
        int b = rand() % 100;
        int res = myf[i](a, b);
        printf("%d %c %d = %d\n", a, operators[i], b, res);
    }*/

    return 0;
}
