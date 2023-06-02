#ifndef __GROUND_H__
#define __GROUND_H__
#include "Screen.h"

class Ground
{
public:
    Ground(int x0, int y0, int w0, int h0, int length);

    void set_sqar_length(int length);

    int get_sqar_length();

    void draw_Ground(Screen *s, int color1, int color2);

    
private:
    int x;
    int y;
    int width;
    int height;
    int sqar_length;
};

#endif