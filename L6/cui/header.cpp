#include "header.h"

Panel::Panel(int x, int y, int w, int h, unsigned short color, string s, Object* parent)
{   
    this->w = w;
    this->h = h;
    this->parent = parent;
    this->s = s;
    this->color = color;

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Object::Adauga(Object* obj)
{
    v.push_back(obj);
}

void Panel::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    char* c = new char[w + 1];
    memset(c, ' ', w);
    c[w] = 0;
    for (int i{ 0 }; i < h; i++)
    {        
        SetConsoleCursorPosition(hh, { (short)x, (short)(y + i) });        
        printf("%s", c);
    }
    delete[] c;
    SetConsoleCursorPosition(hh, { (short)(x+1), (short)(y+1) });
    printf("%s", s.c_str());    
    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();    
}

pair<int, int> Panel::GetPos()
{
    return { x,y };
}

Buton::Buton(int x, int y, int w, int h, unsigned short color, string s, Object* parent)
{
    this->w = w;
    this->h = h;
    this->parent = parent;
    this->s = s;
    this->color = color;

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Buton::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    char* c = new char[w + 1];
    memset(c, ' ', w);
    c[w] = 0;
    for (int i{ 0 }; i < h; i++)
    {
        SetConsoleCursorPosition(hh, { (short)x,(short)(y + i) });
        printf("%s", c);
    }
    delete[] c;
    SetConsoleCursorPosition(hh, { (short)(x+w/2-s.size()/2), (short)(y + 1) });   
    printf("%s", s.c_str());
    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();
}

pair<int, int> Buton::GetPos()
{
    return { x,y };
}

Label::Label(int x, int y, int w, int h, unsigned short color, string s, Object* parent)
{
    this->w = w;
    this->h = h;
    this->parent = parent;
    this->s = s;
    this->color = color;

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Label::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    SetConsoleCursorPosition(hh, { (short)x,(short)(y) });
    char* c = new char[w + 1];
    memset(c, ' ', w);
    c[w] = 0;
    printf("%s", c);
    delete[] c;
    SetConsoleCursorPosition(hh, { (short)(x + w/2 - s.size()/2),(short)(y) });
    printf("%s", s.c_str());
    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();
}

pair<int, int>  Label::GetPos()
{
    return { x,y };
}