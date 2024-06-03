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
    void Adauga(Object*);
    virtual void Desenare() = 0;
    virtual pair<int, int> GetPos() = 0;
};

class Panel : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short color;
public:
    void Desenare();
    pair<int, int> GetPos();
    Panel(int x, int y, int w, int h, unsigned short color, string s, Object* parent=0);
};

class Buton : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short  color;
public:
    void Desenare();
    pair<int, int> GetPos();
    Buton(int x, int y, int w, int h, unsigned short color, string s, Object* parent=0);
};

class Label : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short  color;
public:
    void Desenare();
    pair<int, int> GetPos();
    Label(int x, int y, int w, int h, unsigned short color, string s, Object* parent=0);
};