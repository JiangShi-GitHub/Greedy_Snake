#ifndef __INFOR_H__
#define __INFOR_H__

class Infor
{
private:
    int draw_color;

    int back_color;
public:
    Infor(/* args */);
    
    void tital(int _x, int _y);

    void store();

    void score_show(int _x0, int _y0);


};


#endif