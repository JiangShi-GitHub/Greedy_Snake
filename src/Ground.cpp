#include <iostream>
#include "Ground.h"
#include "Rectangle.h"
using namespace std;

Ground::Ground(int x0, int y0, int w0, int h0, int length)
{
    x = x0;
    y = y0;
    width = w0;
    height = h0;
    sqar_length = length;
}

void Ground::set_sqar_length(int length)
{
    sqar_length = length;
}

int Ground::get_sqar_length()
{
    return sqar_length;
}

void Ground::draw_Ground(Screen *s, int color1, int color2)
{
    bool change_color = 0;

    Rectangle *r = new Rectangle(sqar_length, sqar_length);

    if(width % sqar_length != 0 || height % sqar_length != 0)
    {
        std::cout << "Sorry, w or h is not the multiple of sqar_length" << std::endl;
        throw -1;
    }

    for(int y0 = y; y0 < y + height; y0 += sqar_length)
    {
        for(int x0 = x; x0 < x + width; x0 += sqar_length)
        {
            change_color = !change_color; 
            if(change_color) r -> draw(s, x0, y0, color1);
            else r -> draw(s, x0, y0, color2);
            // std::cout << change_color << " ";
        }
        // std::cout << std::endl;
        if((width / sqar_length) % 2 == 0) change_color = !change_color;
    }

    delete r;
}