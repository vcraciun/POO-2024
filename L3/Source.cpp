#include <iostream>
#pragma warning (disable:4996)

class A {
    int x, y;
    A(int x, int y) : x(x), y(y) { std::cout << "("; }
    static A* inst;
public:
    int computation() {
        return x + y;
    }
    static A* create(int x= 0, int y=0); 
    static void del();
    ~A() { std::cout << ")"; }
};


A* A::inst = 0;
A* A::create(int x, int y) {
    if (inst == 0) {
        inst = new A(x, y);
    }
    return inst;
}
void A::del() {
    delete inst;
}

class B {
    int x;
    char sir[100];
public:
    B(int x, const char* sir): x(x) 
    {
        strcpy(this->sir, sir);
        std::cout << "(";
    }

    B(const B& inst);

    void print()const;

    ~B() { std::cout << ")"; }
};

void B::print()const
{
    std::cout << x << " " << sir;
}

B::B(const B& inst)
{
    this->x = inst.x;
    strcpy(sir, inst.sir);
    std::cout << "(";
}

int main() {
    /*
    std::cout << A::create(1, 1)->computation();
    std::cout << A::create()->computation();
    A::del();
    */

    B b1(5, "abc");
    B b2(10, "xyz");
    B b3(b1);
    B b4 = b2;

    B* bb = (B*)malloc(sizeof(B));
    
    new(bb)B(7, "bcde");
    bb->print();
    bb->~B();
    return 0;
}
