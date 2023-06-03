#ifndef __COLOR_H__
#define __COLOR_H__

typedef struct
{
    double x;
    double y;
} Point;


extern double get_color_line(Point _begin, Point _target, double _x);

extern int get_color(int begin_color, int target_color, double mini, double maxi, double _x);

#endif