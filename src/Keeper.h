#ifndef __KEEPER_H__
#define __KEEPER_H__
#include <list>
#include <thread>
#include <mutex>

enum FoodState
{
    Food_Good,
    Food_Eatten,
    Food_Bad,
};

class Food
{
private:
    int i, j; //食物在草坪上的位置
    int color; //食物颜色

    FoodState state;
public:
    Food(int _i, int _j, int _c, 
         FoodState _s = Food_Good):
            i(_i), j(_j), color(_c), state(_s){}

    int get_i(void) const
    {
        return i;
    }

    int get_j(void) const
    {
        return j;
    }

    void set_i(int _i)
    {
        i = _i;
    }

    void set_j(int _j)
    {
        j = _j;
    }

    FoodState get_state(void) const
    {
        return state;
    }

    void set_state(FoodState _state)
    {
        state = _state;
    }

    //etc
};


class Keeper
{
private:
    std::list<Food> foods; //食物链表

    std::recursive_mutex m;

    int max_foods_num;

    int interval;

    std::thread *t;

public:
    Keeper()
    {
        max_foods_num = 10;
        interval = 8000;

        t = new std::thread(&Keeper::foods, this);
    }
    
    ~Keeper()
    {
        delete t;
    }

    void feed();

    void GenerateFoods();

    void ClearFoods();

    bool is_Food(int _i, int _j);
};

#endif