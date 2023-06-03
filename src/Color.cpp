#include "Color.h"

Point max(Point a, Point b)
{
    if(a.x > b.x) return a;
    else return b;
}

Point min(Point a, Point b)
{
    if(a.x < b.x) return a;
    else return b;
}

int get_color_line(Point _begin, Point _target, int _x)
{
    Point max_p = max(_begin, _target), min_p = min(_begin, _target); //x范围
    if(_x >= max_p.x) return max_p.y;  //如果不在x范围直接返回最大/最小值
    else if(_x <= min_p.x) return min_p.y; 

    double k = (_begin.y - _target.y) / (_begin.x - _target.x); //求k
    double h_b = _begin.y - k * _begin.x; //求b
    return k * _x + h_b; //返回x对应的y值
}

int get_color(int begin_color, int target_color, int mini, int maxi, int _x)
{
    int bB = begin_color | 0xFF, bG = (begin_color >> 8) | 0xFF, bR = (begin_color >> 16) | 0xFF;
    int tB = target_color | 0xFF, tG = (target_color >> 8) | 0xFF, tR = (target_color >> 16) | 0xFF;

    int rB = get_color_line({bB, mini}, {tB, maxi}, _x);
    int rG = get_color_line({bG, mini}, {tG, maxi}, _x);
    int rR = get_color_line({bR, mini}, {tR, maxi}, _x);

    int result = (rR << 16) | (rG << 8) | rB;
    return result;
}