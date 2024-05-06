#include "Header.h"

A::A()
{
    this->x = 0;
}
A::A(int x)
{
    this->x = x;
}
B::B()
{
    this->x = 0;
}
B::B(int x)
{
    this->x = x;
}
C::C()
{
    this->x = 0;
}
C::C(int x)
{
    this->x = x;
}
D::D()
{
    this->x = 0;
}
D::D(int x)
{
    this->x = x;
}
void A::print()
{
    cout <<"A:" << x << endl;

}
void A::change(int x)
{
    this->x = x;
}
void B::print()
{
    cout << "B:" << x << '\n';// ' ' << A::x << endl;

}
void B::change(int x)
{
    this->x = x;
}
void C::print()
{
    cout << "C:" << x << ' ' << A::x << endl;

}
void C::change(int x)
{
    this->x = x;
}
void D::print()
{
    //cout << "D:" << x << " A:" << A::x << " B:" << B::x << " B:A:" << B::A::x << " C:" << C::x << " C:A:" << C::A::x << endl;
    cout << "D:" << x << '\n';
}
void D::change(int x)
{
    this->x = x;
}
