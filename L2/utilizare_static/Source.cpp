#include <stdio.h>
#include <string.h>
#include "header1.h"
#include "header2.h"
#include "common.h"

const char* text = "Hello POO";
int x = 0;
char p = 50;
short q = 'ab';

struct Data {
    int x;
    int y;
    int Calcul() const {
        return x + y;
    }
};

//1025
char* process(int data)
{
    char* result = new char[10];
    memset(result, 0, 10);
    int i = 0;
    while (data) {
        result[i] = data % 10 + '0';
        data /= 10;
        i++;
    }
    return result;
}
int func(int* addr_of_cnt){
    static int counter = 1549;
    *addr_of_cnt = (int)&counter;
    printf("local_counter_addr = %p | %d\n", &counter, counter);
    return counter++;
}

void Test(Data x, const Data& q)
{
    x.x = 10;
    x.y = 20;

    int result = x.Calcul() + q.Calcul();
    printf("Result = %d\n", result);
}

int main(void){
    Data d;
    Data p;
    d.x = 10;
    d.y = 20;
    int res = d.Calcul();
    printf("rest = %d\n", res);
    p.x = 20;
    p.y = 30;

    static int altceva = 1000;
    int y = 100;
    int leaked_static_var = 0;
    printf("local_y_addr = %p\n", &y);
    printf("local_x_addr = %p\n", &x);
    printf("local_p_addr = %p\n", &p);
    printf("local_q_addr = %p\n", &q);
    printf("local_altceva_addr = %p\n", &altceva);
    func(&leaked_static_var);
    *(int*)leaked_static_var = 50;
    func(&leaked_static_var);
    char* conv = process(1025);
    char* conv2 = process(4444);
    printf("conv = %s | %s\n", conv, conv2);
    //for (int i = 0; i < 10; i++)
    //    printf("counter = %d\n", func());
    
    int a = myfa(5, 5);
    int b = myfb(5, 5);
    printf("a=%d , b=%d\n", a, b);

    Test(d, p);

    return 0;
}
