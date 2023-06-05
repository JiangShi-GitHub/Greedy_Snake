#include <iostream>
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

double get_color_line(Point _begin, Point _target, double _x)
{
    Point max_p = max(_begin, _target), min_p = min(_begin, _target); //x范围
    if(_x >= max_p.x) return max_p.y;  //如果不在x范围直接返回最大/最小值
    else if(_x <= min_p.x) return min_p.y; 

    double k = (_begin.y - _target.y) / (_begin.x - _target.x); //求k
    double h_b = _begin.y - k * _begin.x; //求b
    // std::cout << k << " " << h_b << " " << k * _x + h_b << std::endl;
    return k * _x + h_b; //返回x对应的y值
}

int get_color(int begin_color, int target_color, double mini, double maxi, double _x)
{
    double bB = begin_color & 0xFF, bG = (begin_color >> 8) & 0xFF, bR = (begin_color >> 16) & 0xFF; //得到起始颜色的R、G、B
    double tB = target_color & 0xFF, tG = (target_color >> 8) & 0xFF, tR = (target_color >> 16) & 0xFF; //得到结束颜色的R、G、B
 
    int rB = get_color_line({mini, bB}, {maxi, tB}, _x); //求取R直线
    int rG = get_color_line({mini, bG}, {maxi, tG}, _x); //求取G直线
    int rR = get_color_line({mini, bR}, {maxi, tR}, _x); //求取B直线
    
    int result = (rR << 16) | (rG << 8) | rB; //合成颜色
    return result;
}