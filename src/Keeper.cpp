#include <stdlib.h>
#include "Keeper.h"
#include "GameCtl.h"
#include "Snake.h"

void Keeper::feed(void)
{
    while(1)
    {
        GenerateFoods();

        std::this_thread::sleep_for(std::chrono::milliseconds(interval));

        ClearFoods();
    }
}

void Keeper::GenerateFoods()
{
    srandom(time(nullptr));

    std::unique_lock<std::recursive_mutex> l(m);

    for(int t = 0; t < max_foods_num; t++)
    {
        int i = random();
        int j = random();
        
        if(GameCtl::sn -> is_part_of_body(i, j) || is_Food(i, j))
        {
            t--;
            continue;
        }

        int color = Color_Blue;
        Food f(i, j, color);

        foods.push_back(f);

        GameCtl::g -> draw_item(i, j, color);
    }
}

void Keeper::ClearFoods()
{
    std::unique_lock<std::recursive_mutex> l(m);

    for(auto f:foods)
    {
        FoodState state = f.get_state();
        if(state != Food_Eatten)
        {
            GameCtl::g->draw_item(f.get_i(), f.get_j(), g->);
        }
    }
    foods.clear();
}

bool Keeper::is_Food(int _i, int _j)
{
    for(auto fd:foods)
    {
        if(fd.get_i() == _i && fd.get_j() == _j) return 1;
    }
    return 0;
}