#include <stdlib.h>
#include "Keeper.h"

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
        // Food f()
    }
}

void Keeper::ClearFoods()
{
    
}

bool Keeper::is_Food(int _i, int _j)
{
    for(auto fd:foods)
    {
        if(fd.get_i() == _i && fd.get_j() == _j) return 1;
    }
    return 0;
}