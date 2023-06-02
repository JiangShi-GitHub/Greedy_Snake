#include <mutex>
#include "Snake.h"

Snake::Snake(Ground *_g, int _color, int _head_color)
{
    g = _g;
    color = _color;
    head_color = _head_color;
    dir = MovDir_Right;
    speed = 400;
    acc = 50;

    // Body_item b1(10, 10, color), b2(10, 11, color);

    // body.push_back(b1);
    // body.push_back(b2);

    for(int i = 0; i < 10; i++)
    {
        Body_item b1(20, 20 - i, color);
        body.push_back(b1);
    }

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
        Body_item b1(body.front().get_i() + dir_num[dir].first, body.front().get_j() + dir_num[dir].second, head_color); //定义头
        body.front().set_c(color); //改变旧头颜色为身体颜色
        g->draw_item(body.back().get_i(), body.back().get_j(), g->get_item_color(body.back().get_i(), body.back().get_j())); //将尾巴画掉
        body.pop_back(); //从链表中去掉尾巴
        body.push_front(b1); //将新头推进去



        draw();
    }
}