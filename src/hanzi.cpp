#include <stdio.h>
#include <math.h>
#include "Screen.h"
#include "zimo.h"
#include "hanzi.h"

extern Screen *s;

int draw_color = 0x000000;
int back_color = 0xFFFFFF;
int old_wei = 0;

/*
    color_init：初始化打印颜色的函数
    返回值：
        无。
*/
void color_init()
{
    draw_color = 0x000000;
    back_color = 0xFFFFFF;
}

/*
    change_color：改变打印颜色的函数
    @draw：定义画的颜色
    @back：定义背景颜色
    返回值：
        无。
*/
void change_color(int draw, int back)
{
    draw_color = draw;
    back_color = back;
}


/*
    hanzi_display：在屏幕上显示一个汉字或数字
    @x0：显示区域的左上顶点的x轴坐标
    @y0：显示区域的左上顶点的y轴坐标
    @size：要显示的汉字的宽和高的数组
    @data：要显示的汉字或数字的取模后的数据
    返回值：
        无。
*/
void hanzi_display(int x0, int y0, int size[], char data[])
{
    //总共要显示w*h个像素点
    //按扫描的顺序给像素点编号，编号范围[0, w*h)
    int w = size[0];
    int h = size[1];
    int dian; //保存点的编号， [0, w*h)
    int color;
    for(dian = 0; dian < w * h; dian++)
    {
        //显示第dian个像素点
        int index; //第 dian 这个像素点的取模后的数据在 data 中的第 index 个字节中
        int bit; //第 dian 这个像素点的取模后的数据在 data[index] 这个字节中的 第bit个位置
        index = dian / 8;
        bit = 7 - dian % 8;
        if((data[index] >> bit) & 1)
        {
            color = draw_color; //白色
        }
        else
        {
            color = back_color; //黑色
        }

        int x = x0 + dian % w;
        int y = y0 + dian / w;

        s -> draw_point(x, y, color);
    }
}

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
void hanzi_display_wh(int x0, int y0, int w, int h, char data[])
{
    //总共要显示w*h个像素点
    //按扫描的顺序给像素点编号，编号范围[0, w*h)
    int dian; //保存点的编号， [0, w*h)
    int color;
    for(dian = 0; dian < w * h; dian++)
    {
        //显示第dian个像素点
        int index; //第 dian 这个像素点的取模后的数据在 data 中的第 index 个字节中
        int bit; //第 dian 这个像素点的取模后的数据在 data[index] 这个字节中的 第bit个位置
        index = dian / 8;
        bit = 7 - dian % 8;
        if((data[index] >> bit) & 1)
        {
            color = draw_color; //黑色
        }
        else
        {
            color = back_color; //白色
        }

        int x = x0 + dian % w;
        int y = y0 + dian / w;

        s -> draw_point(x, y, color);
    }
}

/*
    show_num：打印数字的函数
    @x0：要打印的数字的初始x轴坐标
    @y0：要打印的数字的初始y轴坐标
    @num：要打印的数字
    返回值：
        无。
*/
void show_num(int x0, int y0, int num)
{
	if(num == 1) hanzi_display(x0, y0, size_er, yi_erhao);
	else if(num == 2) hanzi_display(x0, y0, size_er, er_erhao);
	else if(num == 3) hanzi_display(x0, y0, size_er, san_erhao);
	else if(num == 4) hanzi_display(x0, y0, size_er, si_erhao);
	else if(num == 5) hanzi_display(x0, y0, size_er, wu_erhao);
	else if(num == 6) hanzi_display(x0, y0, size_er, liu_erhao);
	else if(num == 7) hanzi_display(x0, y0, size_er, qi_erhao);
	else if(num == 8) hanzi_display(x0, y0, size_er, ba_erhao);
	else if(num == 9) hanzi_display(x0, y0, size_er, jiu_erhao);
	else if(num == 0) hanzi_display(x0, y0, size_er, ling_erhao);
}


/*
    digital_display：显示数字的函数
    @x0：要显示的数字的初始x轴坐标
    @y0：要显示的数字的初始y轴坐标
    @num：要显示的数字
    返回值：
        无。
*/
void digital_display(int x0, int y0, int num)
{   
    if(num == 0) show_num(x0, y0, num);
    else
    {
        int zh[9], i = 8;
        int zheng = num;
        //printf("%d\n%lf\n", zheng, xiao);
        while(zheng > 0)
        {
            zh[i--] = zheng % 10;
            zheng = zheng / 10;
        }

        int x = x0;
        for(int j = i + 1; j <= 8; j++)
        {
            show_num(x, y0, zh[j]);
            x += size_er[0];
            //printf("%d\n", zh[j]);
        }
    }
}