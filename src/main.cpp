#include <iostream>
#include <unistd.h>
#include "Screen.h"
#include "Rectangle.h"
#include "Ground.h"
#include "main.h"
using namespace std;

int main()
{
    int color1 = 0x555555, color2 = 0xff0000;
    int length = 20;
    Screen *s = new Screen("/dev/fb0");
    Ground g(0, 0, 600, 480, length);
    
    s -> clear();

    
    g.draw_Ground(s, color1, color2);




    delete s;
    return 0;
}