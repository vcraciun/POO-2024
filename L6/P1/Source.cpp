#include "Header.h"

int main() {
    B b;
    C c;
    D d;
    A* arr[3] = { &b ,&c, &d };
    int aux = *(int*)arr[0];
    *(int*)arr[0] = *(int*)arr[2];
    *(int*)arr[2] = aux;
        
    for (size_t i = 0; i < 3; i++) {
        arr[i]->change(i);
        arr[i]->print();
    }

    ((int*)arr[1])[1] = 99;
    arr[1]->print();
    arr[1]->A::print();
    arr[1]->change(55);
    arr[1]->print();
    arr[1]->A::change(33);
    arr[1]->A::print();

    b.change(3);
    c.change(4);
    b.print();
    c.print();
    d.change(5);
    d.print();
    b.A::change(10);
    b.A::print();
    d.B::A::change(7);
    d.B::A::print();
    d.C::A::change(2);
    d.C::A::print();
    return 0;
}




