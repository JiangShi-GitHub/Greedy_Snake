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

    void read_score();

    int get_now_score();

    int get_best_score();

    void draw_progress_bar(int _x, int _y, int _w, int _h, int _begin_color = 0x00FFDA, int _target_color = 0xFF0000);

    void draw_progress_vanish(int _x, int _y, int _w, int _h);
};


#endif