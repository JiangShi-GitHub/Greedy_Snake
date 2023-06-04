#include <mutex>
#include "Snake.h"
#include "Keeper.h"

extern Keeper *k;

Snake::Snake(Ground *_g, int _init_size, int _color, int _head_color)
{
    g = _g;
    color = _color;
    head_color = _head_color;
    dir = MovDir_Right;
    speed = 400;
    acc = 50;
    init_size = _init_size;
    // Body_item b1(10, 10, color), b2(10, 11, color);

    for(int i = 0; i < init_size; i++)
    {
        Body_item b1(20, 20 - i, color);
        body.push_back(b1);
    }

    draw();

    t = new std::thread(&Snake::move, this);
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

        int N = g -> get_lines();
        int M = g -> get_columns();
        int i = b1.get_i(), j = b1.get_j();
        if(i < 0 || i >= N || j < 0 || j >= M || is_part_of_body(i, j))
        {   
            std::cout << ((i < 0) || (i >= N) || (j < 0) || (j >= M) || is_part_of_body(i, j))<< std::endl;
            std::cout << " i= " << i << " N= " << N << " j= " << j << " M= " << M << " body= "<< is_part_of_body(i, j)<< std::endl;
            std::cout << "Game is Over!!!" << std::endl;
            delete k;
            break;
        }

        body.push_front(b1); //将新头推进去

        if(k -> is_food(i, j))
        {
            k -> eat(i, j);
        }
        else
        {
            g->draw_item(body.back().get_i(), body.back().get_j()); //将尾巴画掉
            body.pop_back(); //从链表中去掉尾巴
        }

        draw();
    }
}

bool Snake::is_part_of_body(int _i, int _j)
{
    for(auto fi:body)
    {
        if(fi.get_i() == _i && fi.get_j() == _j) return true;
    }
    return false;
}

void Snake::UpdateEvent(InputEvent e)
{
    MovDir _new_dir = MovDir_Unkown;
    if (e == InputEvent_Left)
    {
        _new_dir = MovDir_Left;
    }
    else if (e == InputEvent_Right)
    {
        _new_dir = MovDir_Right;
    }
    else if (e == InputEvent_Up)
    {
        _new_dir = MovDir_Up;
    }
    else if (e == InputEvent_Down)
    {
        _new_dir = MovDir_Down;
    }


   
    std::unique_lock<std::recursive_mutex> l(m);
    if (is_same(_new_dir) )// if (与原来是相同的方向)
    {
        // 加速
        if (speed > acc) 
            speed -= acc;
    }
    else if (is_opponent(_new_dir))
    {
        //减速
        speed += acc;
    }
    else 
    {
         if (can_change_dir(_new_dir))
        {
            dir = _new_dir;
        }
    }
}


bool Snake::can_change_dir(MovDir _dir )
{

    std::unique_lock<std::recursive_mutex> l(m);
    if (body.size() == 1)
    {
        return true;
    }

    if (_dir == MovDir_Unkown)
    {
        return false;
    }

    auto it = body.begin(); //it指向body这个链表中的第一个元素的迭代器
                            //iterator(“迭代器是像指针一样的东西”)
    Body_item b1 = *it;
    it++; //it指向body这个链表的第二个元素
    Body_item b2 = *it;

    if ((b1.get_i() == b2.get_i()) && (b2.get_j() == b1.get_j() + 1) &&
        (_dir == MovDir_Right))
    {
        return false;
    }
    else if ((b1.get_i() == b2.get_i()) && (b2.get_j() == b1.get_j() - 1) &&
        (_dir == MovDir_Left))
    {
        return false;
    }
    else if ((b1.get_j() == b2.get_j()) && (b2.get_i() == b1.get_i() + 1) &&
        (_dir == MovDir_Down))
    {
        return false;
    }
    else if((b1.get_j() == b2.get_j()) && (b2.get_i() == b1.get_i() - 1) &&
        (_dir == MovDir_Up))
    {
        return false;
    }


    return true;
}