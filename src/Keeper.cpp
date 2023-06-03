

#include <iostream>
#include <chrono>

#include "Keeper.h"
#include "Ground.h"
#include "Snake.h"

extern Ground *g ;//
extern Snake *sn;
void Keeper::feed(void)
{

    while (1)
    {
        //1. 生成“食物”
        GenerateFoods();

        //2. sleep
        std::this_thread::sleep_for( std::chrono::milliseconds(interval));


        //3. 清理 “食物”
        ClearFoods();

       
    }
}




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

    for(Food f: foods)
    {
        FoodState state = f.get_state();
        if (state != Food_Eatten)
        {
            g->draw_item( f.get_i(), f.get_j() );
        }
    }

    foods.clear(); //把链表上所有元素都“干掉”
}