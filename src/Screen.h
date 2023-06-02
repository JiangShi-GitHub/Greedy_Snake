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

    
};

#endif