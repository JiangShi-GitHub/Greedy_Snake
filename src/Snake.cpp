#include <mutex>
#include "Snake.h"

Snake::Snake(Ground *_g)
{
    g = _g;
    color = Color_Red;
    dir = MovDir_Left;
    speed = 400;
    acc = 50;

    Body_item b1(10, 10, color), b2(10, 11, color);

    body.push_back(b1);
    body.push_back(b2);

    draw();
}

void Snake::draw()
{
    std::unique_lock<std::recursive_mutex> l(m);

    if(g == nullptr)
    {
        return;
    }

    for(Body_item x:body)
    {
        g -> draw_item(x.get_i(), x.get_j(), x.get_c());
    }
}

void Snake::move()
{
    while(1)
    {
        //先sleep一段时间
        std::chrono::milliseconds s(speed);
        std::this_thread::sleep_for(s);

        std::unique_lock<std::recursive_mutex> l(m);

        //再移动



        draw();
    }
}