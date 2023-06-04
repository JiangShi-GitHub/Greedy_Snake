#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Infor.h"
#include "Snake.h"
#include "Screen.h"
#include "Color.h"
#include "hanzi.h"
#include "Bmp.h"

extern Snake *sn;

extern Screen *s;
//640 0
Infor::Infor(const char* _File, int _x, int _y)
{
    bmp_display(_File, _x, _y);
    read_score();
    best_score_show();
    now_score = 0;
    now_score_show();
}

void Infor::now_score_show()
{
    now_score = sn -> snake_size() - sn -> get_init_size();
    digital_display(704, 162, now_score);
}

void Infor::best_score_show()
{
    digital_display(682, 415, best_score);
}

void Infor::write_score(int _score)
{
    std::ofstream ofs;
    ofs.open("./score.txt", std::ios::out);
    ofs << _score;
    ofs.close();
}

void Infor::read_score()
{
    std::ifstream ifs;
    ifs.open("./score.txt", std::ios::in);
    if(!ifs.is_open())
    {
        std::cout << "Wrong to read file" << std::endl;
        return;
    }
    char buf[1024] = {0};
    std::string get;
    while(ifs >> buf);
    get = buf;
    ifs.close();
    
    int res = 0;
    std::reverse(get.begin(), get.end());
    // cout << get << endl;
    while(get.size() > 0)
    {
        res *= 10;
        res += (get[get.size() - 1] - '0');
        get.pop_back();
    }
    best_score = res;
}

int Infor::get_now_score()
{
    return now_score;
}

int Infor::get_best_score()
{
    return best_score;
}

void Infor::draw_progress_bar(int _x, int _y, int _w, int _h, int _begin_color, int _target_color)
{
    int x, y;
    for(y = _y; y < _y + _h; y++)
    {
        for(x = _x; x < _x + _w; x++)
        {
            s -> draw_point(x, y, get_color(_begin_color, _target_color, _y, _y + _h, y));
        }
    }
}

void Infor::draw_progress_vanish(int _x, int _y, int _w, int _h)
{
    int x, y;
    for(y = _y; y < _y + _h; y++)
    {
        for(x = _x; x < _x + _w; x++)
        {
            s -> draw_point(x, y, 0xFFFFFF);
        }
    }
}