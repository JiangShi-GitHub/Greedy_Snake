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

    int item_color1;
    int item_color2;
    int colors[800][800] = {{0}};

    int lines;
    int columns;

    Screen *s;
    int x0, y0;

    std::mutex m;

public:
    Ground(int _w, int _h, 
           int _border_size, int _item_size, 
           int _border_color = 0x00, 
           int _item_color1 = 0xFF00, int _item_color2 = 0x01B101):
           Rectangle(_w, _h), border_size(_border_size), 
           item_size(_item_size), border_color(_border_color), 
           item_color1(_item_color1), item_color2(_item_color2),
           s(nullptr), x0(-1), y0(-1)
    {
        lines = (get_h() - 2 * border_size) / item_size;
        columns = (get_w() - 2 * border_size) / item_size;
    }

    int get_item_color(int _i, int _j) const
    {
        if(colors[_i][_j]) return item_color1;
        else return item_color2;
    }

    void set_item_color(int _i, int _j, int _color)
    {
        colors[_i][_j] = _color;
    }

    void draw(Screen *_s, int _x0 = 0, int _y0 = 0);

    void draw_item(int i, int j, int color);

    void draw_item(int i, int j)
    {
        int tmp_color = 0;
        if(colors[i][j]) tmp_color = item_color1;
        else tmp_color = item_color2;
        draw_item(i, j, tmp_color);
    }
};

#endif