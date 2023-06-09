

#include <iostream>
#include <chrono>

#include "Keeper.h"
#include "Ground.h"
#include "Snake.h"
#include "Color.h"
#include "Infor.h"

extern Ground *g ;//
extern Snake *sn;
extern Infor *ifor;

void Keeper::feed(void)
{

    while (1)
    {
        //1. 生成“食物”
        GenerateFoods();
        ifor -> draw_progress_bar(717, 214, 32, 149);
        //2. sleep
        int time_cnt = interval;
        while(time_cnt--)
        {
            disappearFoods(time_cnt);
            if(time_cnt % 50 == 0 || time_cnt == 1) ifor -> draw_progress_vanish(717, 214, 32, 149 - (double)time_cnt / (double)interval * 149.0);
            std::this_thread::sleep_for( std::chrono::milliseconds(1));
        }   
        //3. 清理 “食物”
        ClearFoods();
    }
}


//77 + 640, 214

void Keeper::GenerateFoods(void)
{
    // time( nullptr ) 获取当前的时间
    // 每次运行该程序时的时间是不相同的
    // 这里  srandom( time(nullptr) ) 设置的随机数种子 就不相同
    // 后面调用的 random产生的随机数序列也就不相同
    srandom ( time(nullptr) ); //设置随机数种子

    std::unique_lock< std::recursive_mutex > l (m);

    int N = g->get_lines(); //“草坪上有多少行”
    int M = g->get_columns(); //"草坪上有多少列"

    for(int t = 0; t < max_foods_num; t++)
    {
        int i = random()  % N ; // [0, N)
        int j = random()  % M ; // [0, M)

        if (sn->is_part_of_body(i,j) || is_food(i,j ))
        {
            continue;
        }
        int color = Color_Blue;
        Food f(i,j, color);

        foods.push_back(f);

        g->draw_item(i, j, color);
    }
}


void Keeper::ClearFoods(void)
{
    std::unique_lock< std::recursive_mutex > l (m);

    for(Food f:foods)
    {
        FoodState state = f.get_state();
        if (state != Food_Eatten)
        {
            g->draw_item( f.get_i(), f.get_j() );
        }
    }

    foods.clear(); //把链表上所有元素都“干掉”
}

void Keeper::disappearFoods(int _x)
{
    for(Food f:foods)
    {
        FoodState state = f.get_state();
        if (state != Food_Eatten)
        {
            g->draw_item( f.get_i(), f.get_j(), get_color(g -> get_item_color(f.get_i(), f.get_j()), Color_Blue, 0, interval, _x));
        }
    }
}