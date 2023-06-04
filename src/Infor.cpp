#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Infor.h"
#include "Snake.h"
#include "hanzi.h"
#include "Bmp.h"

extern Snake *sn;
//640 0
Infor::Infor(const char* _File, int _x, int _y)
{
    bmp_display(_File, _x, _y);
    best_score = read_score();
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

int Infor::read_score()
{
    std::ifstream ifs;
    ifs.open("./score.txt", std::ios::in);
    if(!ifs.is_open())
    {
        std::cout << "Wrong to read file" << std::endl;
        return 0;
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
    return res;
}