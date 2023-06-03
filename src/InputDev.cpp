
#include <iostream>
#include <thread>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#include "InputDev.h"
#include "main.h"


InputDev::InputDev(Snake* _s, const char* _dev): 
            s(_s) ,file(_dev)
{
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        std::cout << "failed to open " << file << std::endl;
        throw -1;
    }


    t = new std::thread(&InputDev::read_event, this);


}

void InputDev::read_event(void)
{
   
    struct input_event ev;
    int x1 = -1, y1 = -1;//记录一次滑动过程中的第一个点
    int x2, y2; //记录最后一个点的坐标。
    while (1)
    {
        int ret = read(fd, &ev, sizeof(ev));
        if (ret != sizeof(ev))
        {
            continue;
        }

        //这是一个  x轴事件
        if (ev.type == EV_ABS && ev.code == ABS_X)
        {
            if (x1 == -1)
            {
                x1 = ev.value;
            }
            x2 = ev.value;
           
        }

        //这是一个 y轴事件
        if (ev.type == EV_ABS && ev.code == ABS_Y)
        {
            if (y1 == -1)
            {
                y1 = ev.value;
            }
            y2 = ev.value;
           
        }


        //弹起事件
        if ( (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0) || 
             (ev.type == EV_ABS && ev.code == ABS_PRESSURE && ev.value == 0))
        {
            int delt_x = abs(x2 - x1);
            int delt_y = abs(y2 - y1);

            InputEvent ev = InputEvent_Unkown;
            if (delt_x >= 2*delt_y)
            {
                if (x2 > x1)
                {
                    //上报 “向右 事件”
                    ev = InputEvent_Right;
                }
                else 
                {
                    //上报 “向左 事件”
                    ev = InputEvent_Left;
                }
            }
            else if (delt_y >= 2*delt_x)
            {
                if (y2 > y1)
                {
                    //上报 “向下  事件”
                    ev = InputEvent_Down;
                }
                else 
                {
                    //上报  “向上 事件”
                    ev = InputEvent_Up;
                }
            }
           
            s->UpdateEvent(ev);

            x1 = -1;
            y1 = -1;
          
        }
    }
    
}