

#ifndef __INPUTDEV_H__
#define __INPUTDEV_H__

#include <thread>
#include "Snake.h"

class InputDev
{
private:
    const char* file;
    int fd;

    std::thread *t;

    Snake *s;//
public:
    InputDev(Snake* _s, const char* _dev = "/dev/input/event0");
    ~InputDev();


    void read_event(void);
};




#endif 