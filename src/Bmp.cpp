#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <math.h>
#include "Bmp.h"
#include "Ground.h"

extern Screen *s ;

/*
    bmp_diaplay：在屏幕坐标点（x0，y0）处显示一张bmp图片
    @bmp_file：要显示的图片文件的文件名
    @x0：显示位置的x轴坐标
    @y0：显示位置的y轴坐标
*/
void bmp_display(const char* bmp_file, int x0, int y0)
{
    int fd;
    int width; //获取bmp文件的宽度
    int height; //获取bmp文件的高度
    int depth = 0; //获取bmp文件的色深
    
    fd = open(bmp_file, O_RDONLY);
    if(fd == -1)
    {
        printf("Sorry, file to open %s\n", bmp_file);
        return;
    }

    //获取bmp文件的宽度
    lseek(fd, 0x12, SEEK_SET);
    read(fd, &width, 4);

    //获取bmp文件的高度
    lseek(fd, 0x16, SEEK_SET);
    read(fd, &height, 4);

    //获取bmp文件的色深
    lseek(fd, 0x1c, SEEK_SET);
    read(fd, &depth, 2);

    if(!(depth == 24 || depth == 32)){
        //printf("Width: %d\nHeight: %d\nDepth: %d\n", width, height, depth);
        printf("Sorry, NOT SUPPORT!!\n");
        close(fd);
        return;
    }

    //printf("Width: %d\nHeight: %d\nDepth: %d\n", width, height, depth);

    int valid_line_bytes; //一行有效的字节数
    int laizi = 0; //每行末尾的“赖子”的数量
    int total_line_bytes; //一行总字节数
    int total_bytes; //整个像素数组的字节数

    valid_line_bytes = abs(width) * (depth / 8);
    if(valid_line_bytes % 4)
    {
        laizi = 4 - valid_line_bytes % 4;
    }
    total_line_bytes = valid_line_bytes + laizi;
    total_bytes = total_line_bytes * abs(height);

    char* p = (char*)malloc(total_bytes);
    lseek(fd, 54, SEEK_SET);
    read(fd, p, total_bytes);

    unsigned char a = 0, r, g, b;
    int color;
    int i = 0;

    for(int y = 0; y < abs(height); y++)
    {
        for(int x = 0; x < abs(width); x++)
        {
            b = p[i++];
            g = p[i++];
            r = p[i++];
            if(depth == 32)
            {
                a = p[i++];
            }
            color = (a << 24) | (r << 16) | (g << 8) | b;
            s -> draw_point(x0 + x, y0 + height - 1 - y, color);
        }
        i += laizi;
    }
    

    close(fd);
    free(p);
}