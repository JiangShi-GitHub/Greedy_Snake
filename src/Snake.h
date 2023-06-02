#ifndef __SNAKE_H__
#define __SNAKE_H__
#include <queue>
#include<utility>
#include "Screen.h"

class Snake
{
private:
    int x;
    int y;
    int Snake_length;
    int add_num;
    int Snake_color;
    std::pair<int,int> dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    std::queue<std::pair<int,int>> q;
public:
    Snake(int x0, int y0, int color);

    void set_Snake_color(int color);

    void move(int dir_select);

    void eat(int count);

    void die();
    
    void draw_Snake(Screen *s, int x0, int y0);
};

#endif