
#ifndef __KEEPER_H__
#define __KEEPER_H__
#include <list>
#include <mutex>
#include <thread>

enum FoodState
{
    Food_Good, //新鲜的
    Food_Eatten, //被吃掉了
    Food_Bad, //腐烂了
};

// "食物"
class Food
{
private:
    int i, j; //“食物在草坪上的位置”
    int color; //“食物颜色”

    FoodState state;
public:

    Food(int _i, int _j, int _c,
        FoodState _s = Food_Good):
            i(_i), j(_j), color(_c), state(_s)
    {}

    int get_i(void) const 
    {
        return i;
    }

    int get_j(void) const 
    {
        return j;
    }

    int get_color(void) const 
    {
        return color;
    }

    FoodState get_state(void) const 
    {
        return state;
    }

    void set_state(FoodState _s)
    {
        state = _s;
    }
};


// "饲养员"
class Keeper
{
private:
    std::list<Food> foods; //食物链表

    std::recursive_mutex m; //保护 “foods”

    int max_foods_num; //一次性生成最大的食物数

    int interval; //"喂养时间间隔" 单位 毫秒

    std::thread *t;
public:
    Keeper(/* args */)
    {
        max_foods_num = 10;
        interval = 8000;

        t = new std::thread(&Keeper::feed, this);
    }
    ~Keeper()
    {
        delete t;
    }


    void feed(); //“喂养线程”

    void GenerateFoods(); //生成食物
    void ClearFoods(); //清理食物



    bool is_food(int i, int j)
    {
        std::unique_lock< std::recursive_mutex > l (m);
        for (Food f: foods)
        {
            if (f.get_i() == i && f.get_j() == j)
            {
                return true;
            }
        }

        return false;
    }


    void eat(int i, int j)
    {
        std::unique_lock< std::recursive_mutex > l (m);
        for (Food& f: foods)
        {
            if (f.get_i() == i && f.get_j() == j)
            {
                f.set_state(Food_Eatten);
            }
        }
    }
};




#endif 