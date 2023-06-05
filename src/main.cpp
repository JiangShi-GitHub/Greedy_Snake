#include <iostream>
#include <stdio.h>
#include <sys/types.h>   
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

#include "Rectangle.h"
#include "Screen.h"
#include "Ground.h"
#include "Snake.h"
#include "Keeper.h"
#include "InputDev.h"
#include "Color.h"
#include "Infor.h"

// It is ugly. 全部设置成“全局变量”是有问题的
Screen* s = nullptr;
Ground* g = nullptr;
Snake* sn = nullptr;
Keeper* k = nullptr;
InputDev *dev1 = nullptr;
Rectangle *r = nullptr;
Infor *ifor = nullptr;

std::string Rand_background()
{
    std::vector<std::string> back; //存放背景名称
    back.clear(); //清空一下Vector
    const char* path = "./backgrounds/"; //图片地址
    DIR *dp = opendir(path); //打开文件目录
    struct dirent *p; //结构体指针
    int back_cnt = 0;

    while(p = readdir(dp)) //遍历目录
    {
        if(p -> d_type == DT_REG) //如果为文件
        {
            if(strstr(p ->d_name, ".bmp")) //如果名称包含“.bmp”
            {
                back.push_back(p -> d_name); //压入Vector
                back_cnt++;
            }
        }
    }

    srandom ( time(nullptr) ); //设置随机数种子
    std::string rand_back = back[rand() % back_cnt]; //随机一个文件
    std::string res = path + rand_back; //加上路径
    return res;
}

int main()
{   
    // std::cout << Rand_background() << std::endl;

    s = new Screen("/dev/fb0");
    s->clear();

    std::string get_pic = Rand_background();
    const char *pic = get_pic.c_str();
    g = new Ground(640, 480, 5, 5, 0xFF0000, 0xFFFFFF, 0xD2D2D0);
    g->draw(s, pic, 0, 0);

    sn = new Snake(g, 5, 0xB20101);

    ifor = new Infor("infor.bmp", 640, 0);

    k = new Keeper();
    dev1 = new InputDev(sn, "/dev/input/event0");

    system("madplay -r ./*.mp3 &");
   
    while (1)
    {

    }

    delete sn;
    delete g;
    delete s;

    return 0;
}

 // r = new Rectangle(100, 100);
    // for(int i = 0; i <= 1000; i++)
    // {
    //     r->draw(s, 0, 0, get_color(0xFF0000, 0xFFFFFF, 0, 1000, i));
    //     // usleep(100);
    // }
