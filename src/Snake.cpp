#include <iostream>
#include <queue>

#include "Snake.h"
#include "Rectangle.h"
#include "Ground.h"
using namespace std;

#define fi first
#define se second

Snake::Snake(int x0, int y0, int color)
{
    x = x0;
    y = y0;
    Snake_length = 10;
    add_num = 0;
    Snake_color = color;
    q.push({x, y});
}

void Snake::set_Snake_color(int color)
{
    Snake_color = color;
}

void Snake::move(int dir_select)
{
    x = x + dir[dir_select].fi;
    y = y + dir[dir_select].se;
    q.push({x, y});
    if(!add_num) q.pop();
    else add_num--;
}

void Snake::eat(int count)
{
    add_num = count;
}

void Snake::draw_Snake(Screen *s, int x0, int y0)
{
    Rectangle *r = new Rectangle(x0, y0);
    
    // for(auto x:q)
    // {
    //     r -> draw(s, x.fi, x.se, Snake_color);
    // }
}

