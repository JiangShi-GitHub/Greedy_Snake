#ifndef __SCREEN_H__
#define __SCREEN_H__

class Screen
{
private:
    const char* file;
    int fd;
    int width;
    int height;
    int *plcd;
public:
    Screen(const char* _dev = "/dev/fb0");

    ~Screen();

    inline void draw_point(int x, int y, int color)
    {
        if(plcd && x >= 0 && x < width && y >= 0 && y < height)
        {
            *(plcd + y * width + x) = color;
        }
    }

    void clear(int color = 0xffffff)
    {
        for(int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                draw_point(x, y, color);
            }
        }
    }

    void clear_area(int x0, int y0, int x1, int y1, int color)
    {
        if(x0 < x1)
        {
            switch(x0, x1);
            switch(y0, y1);
        }
        for(int j = y0; j < y1; j++)
        {
            for(int i = x0; i < x1; i++)
            {
                draw_point(i, j, color);
            }
        }
    }
};

#endif