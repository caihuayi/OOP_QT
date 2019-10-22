#include "window.h"

Window::Window():Rectangle()
{
    f_width = 0;
    t_height = 0;
    state = RELEASE;
}

Window::Window(int w, int h, int l, int u, int r, int d):Rectangle(l, u, r, d)
{
    f_width = w;
    t_height = h;
    state = RELEASE;
}

void Window::onPress(int x, int y)
{
    if(left < x && x < right &&up < y && y <up + t_height)
        state = TITLE;	// 选中标题
    if(left <= x+15 && left >= x-15 && up < y && down > y)   state = LEFT;	// 选中左边
    if(up <= y+15 && up >= y-15 && left < x && right > x)		state = UP;
    if(right <= x+15 && right >= x-15 && up < y && down > y)	state = RIGHT;
    if(down <= y+15 && down >= y-15 && left < x && right > x)	state = DOWN;	// 选中下边
}

void Window::onRelease(int x, int y)
{
    ord_x = x;
    ord_y = y;
    state = RELEASE;
}

void  Window::onMove(int cx, int cy)
{
    if(state == TITLE)
    {
        Offset(cx, cy);		//  位移量cx,cy
    }
    else if(state == LEFT)
    {
        onSize(-cx, 0);
        Offset(cx/2, 0);
    }
    else if(state == UP)
    {
        onSize(0, -cy);
        Offset(0, cy/2);
    }
    else if(state == RIGHT)
    {
        onSize(cx, 0);
        Offset(cx/2, 0);
    }
    else if(state == DOWN)
    {
        onSize(0, cy);
        Offset(0, cy/2);
    }		//	先改变大小，再移动半幅
}

QLine Window::toQtLine()
{
    QLine line;
    line.setLine(left, up+t_height, right, up+t_height);
    return line;
}

void Window::create(int x, int y)
{
    this->up = y + ord_y;
    this->down = y+50+ord_y;
    this->left = x + ord_x;
    this->right = x+50+ord_x;
}
