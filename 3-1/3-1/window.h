#ifndef WINDOW_H
#define WINDOW_H
#include "rectangle.h"

class Window : public Rectangle
{
private:
    int f_width;
    int t_height;
    int state;
    enum {RELEASE = -1,TITLE = 0, LEFT = 1, UP = 2, RIGHT = 3, DOWN = 4};
public:
    Window();
    Window(int w, int h, int l, int u, int r, int d);
    void onPress(int x, int y);
    void onMove(int cx, int cy);
    void onRelease(int x, int y);
    void create(int x, int y);
    int ord_x;
    int ord_y;
    QLine toQtLine();
};

#endif // WINDOW_H
