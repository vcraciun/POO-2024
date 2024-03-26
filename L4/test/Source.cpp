#include "Header.h"

#define FUNCTIE_SECRETA(a,b) ((a<<b) | (a>>(8-b)))

extern void FunctieDubioasa();

int main()
{
    Data x = { 0 };
    int f = x.f1(100, 1);
    int g = x.f2(10, 50);
    printf("f=%d\ng=%d\n", f, g);
    Clasa2 d;
    cout << "secret = " << d.func(10) << endl;

    FunctieDubioasa();

    return 0;
}
