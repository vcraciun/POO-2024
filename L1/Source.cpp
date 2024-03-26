#include <stdio.h>
#include "common.h"

int x = 10;
//12, 16, 32, 24
struct S {
    char a1;
    short a2;
    long long a3;
    char a4;
};

int main()
{
    S s;
    s.a1 = 'a';
    s.a2 = 'bb';
    s.a3 = 0x3031323334353637;
    s.a4 = 0;
    printf("sizeof(S) = %d\n", sizeof(S));

    //printf("x = %d\n", x);
    /*printf("x = %d\n", x);
    my_function();
    printf("x = %d\n", x);
    char mem[11] = { 1, 1, 2, -1, 0, 2, -2, 3, 97, 48, 65 }; //00
    char mem2[10] = { 66, 0, 0, 0, 1, 1, 1, 1, 2, 2 };
    short f = ((short*)(mem + 3))[0]; //255
    int q = *(int*)(mem + 1);
    char* s = (char*)(mem + 8);
    short r = ((short*)mem)[4];
    printf("f = %d | q = %08X | r = %c%c\n", f, q, r/256, r%256);
    int u = *((int*)mem + 2);
    printf("u = %X | s = %s\n", u, s);
    char w = ((char*)&f)[1];   //0x00
    short e = ((short*)&q)[1]; //0xFF - 255
    printf("w = %X | e = %X\n", w ,e);
    */

    return 0;
}
