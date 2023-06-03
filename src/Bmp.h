#ifndef __BMP_H__
#define __BMP_H__
/*
    bmp_diaplay：在屏幕坐标点（x0，y0）处显示一张bmp图片
    @bmp_file：要显示的图片文件的文件名
    @x0：显示位置的x轴坐标
    @y0：显示位置的y轴坐标
*/
extern void bmp_display(const char* bmp_file, int x0, int y0);

#endif