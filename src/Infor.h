#ifndef __INFOR_H__
#define __INFOR_H__

class Infor
{
private:
    int draw_color;

    int back_color;

    int now_score;

    int best_score;
public:
    Infor(const char* _File, int _x = 0, int _y = 0);
    
    void show(int _x, int _y);

    void now_score_show();

    void best_score_show();

    void write_score(int _score);

    int read_score();
};


#endif