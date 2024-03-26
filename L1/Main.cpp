#include <stdio.h>

int p = 10;

void f1();
void f2();

#pragma pack(1)
struct S {
    short f;
    short t;
    int dif;
    long long u;
    long long nul;
};

int main()
{
    S s;
    s.f = 'a';
    s.t = 'bb'; //0x6262
    s.u = 0x3031323334353637;
    s.nul = 0;

    printf("S.f = %d | S.t = %X | S.u = %s\n", s.f, s.t, (char*)&s.u);
    //0x6261
    printf("?? = %X\n", *(short*)((char*)&s.t - 1));
    printf("sizeof(S) = %d\n", sizeof(S));

    return 0;
}

void f2()
{
    int x = 100;
    printf("p=%d, x=%d\n", p, x);
    printf("&p = %p | &x = %p\n", &p, &x);
}

void f1()
{
    char arr[10] = { 1,1,1,1,2,0,4,3,9,2 };
    int nr1 = *(short*)(arr + 4);
    int nr2 = ((int*)(arr + 8))[0];
    int nr3 = ((int*)(arr + 1))[1];
    //nr1 = 0x0002
    //nr2 = 0x????0209
    //nr3 = 0x09030400
    printf("nr1 = %04X | nr2 = %08X | nr3 = %08X\n", nr1, nr2, nr3);
}
