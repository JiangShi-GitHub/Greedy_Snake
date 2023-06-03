
#include <iostream>

#include "Rectangle.h"

#include "Screen.h"
#include "Ground.h"
#include "Snake.h"
#include "Keeper.h"
#include "InputDev.h"

// It is ugly. 全部设置成“全局变量”是有问题的
Screen* s = nullptr;
Ground* g = nullptr;
Snake* sn = nullptr;
Keeper* k = nullptr;
InputDev *dev1 = nullptr;

int main()
{
    // std::cout << "Hello World" << std::endl;
    
    s = new Screen("/dev/fb0");
    s->clear();


    g = new Ground(640, 480, 5, 5, 0xFF0000, 0xFFFFFF, 0xD2D2D0);
    g->draw(s, 0, 0);




    sn = new Snake(g, 0xB20101);

    k = new Keeper();
    dev1 = new InputDev(sn, "/dev/input/event0");

    while (1)
    {
        
    }

    delete sn;
    delete g;
    delete s;

    return 0;
}