#ifndef __GROUND_H__
#define __GROUND_H__

#include <mutex>
#include "Rectangle.h"
#include "Screen.h"

class Ground: public Rectangle
{
private:
    int border_size;
    int border_color;
    int item_size;

    int item_color;

    int lines;
    int columns;

    Screen *s;
    int x0, y0;

    std::mutex m;

public:
    Ground(int _w, int _h, 
           int _border_size, int _item_size, 
           int _border_color = 0x00, 
           int _item_color = 0xFF00):
           Rectangle(_w, _h), border_size(_border_size), 
           item_size(_item_size), border_color(_border_color), 
           item_color(_item_color), 
           s(nullptr), x0(-1), y0(-1)
    {
        lines = (get_h() - 2 * border_size) / item_size;
        columns = (get_w() - 2 * border_size) / item_size;
    }

    void draw(Screen *_s, int _x0 = 0, int _y0 = 0);

    void draw_item(int i, int j, int color);

    void draw_item(int i, int j)
    {
        draw_item(i, j, item_color);
    }
};

#endif