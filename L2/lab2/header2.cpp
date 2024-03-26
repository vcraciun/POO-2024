#include "header2.h"
#include "common.h"

int my_secret_func(int a, int b)
{
    return a * b;
}

int myfb(int a, int b)
{
    return my_secret_func(a, b) + 2;
}

int my_extra_f()
{
    return 10;
}
//17