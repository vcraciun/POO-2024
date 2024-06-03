#include "header.h"

int main()
{
    Object* p1 = new Panel(5, 5, 100, 40, 0xE0, "Panel 1", nullptr);
    Object *p2 = new Panel(5, 5, 40, 30, 0x90, "Panel 2", p1);
    Object* p3 = new Panel(55, 5, 40, 30, 0xA0, "Panel 3", p1);
    Object* p4 = new Panel(5, 5, 30, 10, 0x4f, "Panel 4", p2);
    Object* b1 = new Buton(10, 3, 10, 3, 0xf0, "Buton 1", p4);
    Object* b2 = new Buton(15, 18, 10, 3, 0xf0, "Buton 2", p2);
    Object* b3 = new Buton(15, 23, 10, 3, 0xf0, "Buton 3", p2);
    Object* L1 = new Label(10, 7, 10, 1, 0x1f, "Label 1", p4);
    
    Object* b4 = new Buton(15, 8, 10, 3, 0xf0, "Buton 4", p3);
    Object* b5 = new Buton(15, 23, 10, 3, 0xf0, "Buton 5", p3);
    Object* L2 = new Label(15, 13, 10, 1, 0x1f, "Label 2", p3);
    Object* L3 = new Label(15, 20, 10, 1, 0x1f, "Label 3", p3);

    p1->Desenare();
    return 0;
}



