#include "header1.h"
#include "common.h"

int my_secret_func(int a, int b)
{
    return a + b;
}

int myfa(int a, int b)
{
    return my_secret_func(a, b) + 5;
}
//13