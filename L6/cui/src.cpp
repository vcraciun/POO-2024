#include "header.h"

int main()
{
    Object* p = new Panel(5, 5, 10, 5, "abc", nullptr);
    p->Desenare();

    Object* b = new Buton(6, 6, 5, 2, "abcc", nullptr);
    b->Desenare();
}
