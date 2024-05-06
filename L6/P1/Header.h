#pragma once
#include <iostream>
using namespace std;

class A
{
protected:
    int x;
public:

    A();
    A(int x);
    virtual void print();
    virtual void change(int x);
    
};

class B: virtual public A
{
protected:
    int x;
 public:

    B();
    B(int x);
    void print();
    void change(int x);

};
class C: virtual public A
{
protected:
    int x;
public:

    C();
    C(int x);
    void print();
    void change(int x);

};
class D : public B, public C
{
    int x;
public:

    D();
    D(int x);
    void print();
    void change(int x);

};
