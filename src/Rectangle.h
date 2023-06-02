#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__
#include "Screen.h"

class Rectangle
{
private:
    int w;
    int h;

public:
    Rectangle(int _w, int _h)
    {
        w = _w;
        h = _h;
    }

    void set_w(int _w)
    {
        w = _w;
    }

    void set_h(int _h)
    {
        h = _h;
    }

    int get_w(void) const
    {
        return w;
    }

    int get_h(void) const
    {
        return h;
    }

    void draw(Screen *s, int x0, int y0, int _color)
    {
        int x, y;
        for(y = y0; y < y0 + h; y++)
        {
            for(x = x0; x < x0 + w; x++)
            {
                s -> draw_point(x, y, _color);
            }
        }
    }
};

#endif