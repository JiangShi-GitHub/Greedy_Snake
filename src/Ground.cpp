#include <iostream>
#include "Ground.h"
#include "Bmp.h"

void Ground::draw(Screen *_s, const char* _File, int _x0, int _y0)
{
    s = _s;
    x0 = _x0;
    y0 = _y0;

    Rectangle ra(get_w(), border_size);
    Rectangle rc(ra);
    Rectangle rb(border_size, get_h());
    Rectangle rd(rb);
    Rectangle re(get_w() - 2 * border_size, get_h() - 2 * border_size);

    ra.draw(s, x0, y0, border_color);
    rc.draw(s, x0, y0 + get_h() - border_size, border_color);
    rb.draw(s, x0 + get_w() - border_size, y0 + border_size, border_color);
    rd.draw(s, x0, y0 + border_size, border_color);

    // re.draw(s, x0 + border_size, y0 + border_size, item_color1);

    bmp_analyze(_File);

    for(int i = 0; i < lines; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            draw_item(i, j, colors[i][j]);   
        }
    }

    std::cout << lines << " " << columns << std::endl;
}

void Ground::draw_item(int i, int j, int color)
{
    if(i >= 0 && i < lines && j >= 0 && j < columns)
    {
        std::unique_lock<std::mutex> l(m);

        Rectangle r(item_size, item_size);
        int x, y;
        x = x0 + border_size + j * item_size;
        y = y0 + border_size + i * item_size;

        r.draw(s, x, y, color);
    }
}