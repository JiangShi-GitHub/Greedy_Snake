#ifndef __GAMECTL_H__
#define __GAMECTL_H__
#include "Screen.h"
#include "Snake.h"
#include "Ground.h"

class GameCtl
{
private:
    
public:

    static Screen *s;

    static Ground *g;

    static Snake *sn;

    GameCtl(){}
    ~GameCtl(){}

};
#endif