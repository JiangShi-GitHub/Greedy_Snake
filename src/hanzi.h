#ifndef __HANZI_H__
#define __HANZI_H__

typedef struct
{
    double x;
    double y;
}RGB_Point;

/*
    hanzi_display：在屏幕上显示一个汉字或数字
    @x0：显示区域的左上顶点的x轴坐标
    @y0：显示区域的左上顶点的y轴坐标
    @size：要显示的汉字的宽和高的数组
    @data：要显示的汉字或数字的取模后的数据
    返回值：
        无。
*/
extern void hanzi_display(int x0, int y0, int size[], char data[]);

/*
    hanzi_display_wh：在屏幕上显示一个汉字或数字
    @x0：显示区域的左上顶点的x轴坐标
    @y0：显示区域的左上顶点的y轴坐标
    @w：要显示的汉字或数字的宽
    @h：要显示的汉字或数字的高
    @data：要显示的汉字或数字的取模后的数据
    返回值：
        无。
*/
extern void hanzi_display_wh(int x0, int y0, int w, int h, char data[]);

/*
    digital_display：显示数字的函数
    @x0：要显示的数字的初始x轴坐标
    @y0：要显示的数字的初始y轴坐标
    @num：要显示的数字
    返回值：
        无。
*/
extern void digital_display(int x0, int y0, int num);

/*
    tital_display：显示标题的函数
    @x0：标题的初始x轴坐标
    @y0：标题的初始y轴坐标
    返回值：
        无。
*/
extern void tital_display(int x0, int y0);

/*
    show_num：打印数字的函数
    @x0：要打印的数字的初始x轴坐标
    @y0：要打印的数字的初始y轴坐标
    @num：要打印的数字
    返回值：
        无。
*/
extern void show_num(int x0, int y0, int num);

/*
    color_init：初始化打印颜色的函数
    返回值：
        无。
*/
extern void color_init();

/*
    change_color：改变打印颜色的函数
    @draw：定义画的颜色
    @back：定义背景颜色
    返回值：
        无。
*/
extern void change_color(int draw, int back);

/*
    RGB_color：根据x坐标改变RGB颜色
    @mini：起始点
    @maxi：结束点
    @best：最佳点
    @x：求取的x坐标
    返回值：
        int类型的RGB数字。
*/
extern int RGB_color(double mini, double maxi, double best, double x);

/*
    get_line_y：求取R、G、B直线并且返回对应的R、G、B值
    @a：直线点1
    @b：直线点2
    @x：求取的x坐标
    返回值：
        int：求取的R、G、B值。
*/
extern int get_line_y(RGB_Point a, RGB_Point b, double x);

extern void hanzi_RGB_display(int x0, int y0, int size[], char data[]);
#endif