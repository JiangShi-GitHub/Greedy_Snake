#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <pthread.h>
#include "Screen.h"
using namespace std;

Screen::Screen(const char* _dev)
{
    file = _dev;
    
    fd = open(file, O_RDWR);
    if(fd == -1)
    {
        cout << "failed to open" << file << endl;
        throw -1;
    }

    width = 800;
    height = 480;

    plcd = (int*)mmap(nullptr, 800*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if(plcd == MAP_FAILED)
    {
        cout << "failed to mmap" << endl;
        throw -2;
    }
}

Screen::~Screen()
{
    munmap(plcd, 800*400*4);
    close(fd);
}