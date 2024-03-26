#include <iostream>

class A {
    int x, y;
public:
   A(int x, int y);
   virtual ~A();
  int calcul();
};
class B: public A{
    int a, b;
public:
    B(int a, int b);
    ~B();
   int calcul();
};
int A::calcul() {
    return x + y;
}

int B::calcul() {
    return a * b;
}

A::~A() {
    std::cout << "]";
}

B::~B() {
    std::cout << ")";
}

A::A(int x, int y): x(x), y(y) {
    std::cout << "[";
}

B::B(int a, int b) : a(a), b(b), A(a, b) {
    std::cout << "(";
}

void main(){
    A* b = (A*) new B(5, 5);
    int c = b->calcul();
    std::cout << c;
    delete b;
}
