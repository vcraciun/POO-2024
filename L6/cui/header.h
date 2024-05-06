#pragma once

#include <vector>
#include <string>
#include <windows.h>
using namespace std;

class Object
{
protected:
    vector<Object*> v;
public:
    virtual void Desenare() = 0;
    virtual void Adauga(Object*) = 0;
    virtual pair<int, int> GetPos() = 0;
};

class Panel : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
public:
    void Desenare();
    void Adauga(Object*);
    Panel(int x, int y, int w, int h, string s, Object* parent);
    pair<int, int> GetPos();
};

class Buton : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
public:
    void Desenare();
    void Adauga(Object*);
    Buton(int x, int y, int w, int h, string s, Object* parent);
    pair<int, int> GetPos();
};

class Label : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
public:
    void Desenare();
    void Adauga(Object*);
    Label(Object* parent, int x, int y, int w, int h, string s);
    pair<int, int> GetPos();
};