#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <iostream>
#include <list>
#include <thread>
#include <utility>
#include "Ground.h"

class Body_item
{
private:
    int i, j;
    int color;
public:
    Body_item(int _i, int _j, int _c):
              i(_i), j(_j), color(_c)
    {}

    void set_i(int _i)
    {
        i = _i;
    }

    void set_j(int _j)
    {
        j = _j;
    }

    int get_i(void) const
    {
        return i;
    }

    int get_j(void) const
    {
        return j;
    }

    void set_c(int _c)
    {
        color = _c;
    }

    int get_c(void) const
    {
        return color;
    }
};

enum MovDir
{
    MovDir_Unkown = 0,
    MovDir_Stop = 0,
    MovDir_Left = 1,
    MovDir_Right = 2,
    MovDir_Up = 3,
    MovDir_Down = 4
};

enum Color_t
{
    Color_Red = 0xFF0000,
    Color_Green = 0x00FF00
};

class Snake
{
private:
    std::list<Body_item> body;//"蛇身"

    int color;
    int head_color;
    MovDir dir;

    int speed;//蛇移动的速度，每隔 多少毫秒 移动一格

    int acc;//"加速度/减速度"

    Ground *g;//蛇在哪个草坪上

    //std::recursive_mutx 递归互斥锁，允许 “锁了又锁”
    std::recursive_mutex m;

    std::thread *t;

    std::pair<int, int> dir_num[5] = {{0, 0}, {0 ,-1}, {0, 1}, {-1, 0}, {1, 0}};

public:
    Snake(Ground *g = nullptr, int _color = Color_Red, int _head_color = 0x049C12);

    ~Snake()
    {
        delete t;
    }

    void draw();

    void move(void); //蛇移动的线程函数

    bool is_part_of_body(int _i, int _j);
};

#endif