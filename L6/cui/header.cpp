#include "header.h"

Panel::Panel(int x, int y, int w, int h, string s, Object* parent)
    : x{x}, y{y}, w{w}, h{h}, s{s}, parent{parent}
{
}

void Panel::Adauga(Object* obj)
{
    v.push_back(obj);
}

void Panel::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!parent)
    {
        for (int i{ 0 }; i < h; i++)
        {        
            SetConsoleCursorPosition(hh, { (short)x,(short)(y + i) });
            char* c = new char[w + 1];
            memset(c, 177, w);
            c[w] = '\0';
            printf("%s", c);
        }
    }
}

pair<int, int> Panel::GetPos()
{
    return { x,y };
}

Buton::Buton(int x, int y, int w, int h, string s, Object* parent)
    : x{ x }, y{ y }, w{ w }, h{ h }, s{ s }, parent{ parent }
{
}

void Buton::Adauga(Object* obj)
{
    v.push_back(obj);
}

void Buton::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!parent)
    {
        SetConsoleTextAttribute(hh, 0x1f);
        for (int i{ 0 }; i < h; i++)
        {
            SetConsoleCursorPosition(hh, { (short)x,(short)(y + i) });
            char* c = new char[w + 1];
            memset(c, 177, w);
            c[w] = '\0';
            printf("%s", c);
        }
    }
}

pair<int, int> Buton::GetPos()
{
    return { x,y };
}