#include "rectangle.h"

Rectangle::Rectangle()
{
    left = 0;
    up = 0;
    right = 0;
    down = 0;
}

Rectangle::Rectangle(int l, int u, int r, int d)
{
    left = l;
    up = u;
    right = r;
    down = d;
}

void Rectangle::Offset(int cx, int cy)
{
    left += cx;
    right +=cx;
    up += cy;
    down += cy;
}

void Rectangle::onSize(int cx, int cy)
{
    left -= cx/2;
    up -= cy/2;
    down += cy/2;
    right += cx/2;
}

QPoint Rectangle::getPnt()
{
    QPoint pnt;
    pnt.setX(left);
    pnt.setY(up);

    return pnt;
}

int Rectangle::getHeight()
{
    return down - up;
}

int Rectangle::getWidth()
{
    return right - left;
}

QRect Rectangle::toQtRect()
{
    QRect rect;
    rect.setRect(getPnt().x(), getPnt().y(), getWidth(), getHeight());
    return rect;
}
