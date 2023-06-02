#include <iostream>
#include <unistd.h>
#include "Screen.h"
#include "Rectangle.h"
#include "Ground.h"
#include "Snake.h"

using namespace std;

int main()
{
    Screen *s = new Screen("/dev/fb0");
    s -> clear();

    Ground *g = new Ground(640, 480, 5, 5, 0xFF0000);
    g -> draw(s, 0, 0);

    Snake *sn = new Snake(g);

    sn->move();

    delete s;
    delete g;
    delete sn;
    return 0;
}