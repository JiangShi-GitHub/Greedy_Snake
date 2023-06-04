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
        return colors[_i][_j];
    }

    void set_item_color(int _i, int _j, int _color)
    {
        colors[_i][_j] = _color;
    }

    void draw(Screen *_s, const char* _File, int _x0 = 0, int _y0 = 0);

    void draw_item(int i, int j, int color);

    void draw_item(int i, int j)
    {
        int tmp_color = 0;
        tmp_color = colors[i][j];
        draw_item(i, j, tmp_color);
    }

    int get_lines(void) const
    {
        return lines;
    }

    int get_columns(void) const
    {
        return columns;
    }
};

#endif