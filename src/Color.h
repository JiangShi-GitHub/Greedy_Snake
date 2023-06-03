#ifndef __COLOR_H__
#define __COLOR_H__

typedef struct
{
    int x;
    int y;
} Point;


extern int get_color_line(Point _begin, Point _target, int _x);

extern int get_color(int begin_color, int target_color, int mini, int maxi, int _x);

#endif