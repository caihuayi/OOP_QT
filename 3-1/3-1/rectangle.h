#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPoint>
#include <QPainter>
class Rectangle
{
protected:
    int left, up, right, down;
public:
    Rectangle();
    Rectangle(int l, int u, int r, int d);
    void Offset(int cx, int cy);
    void onSize(int cx, int cy);
    QPoint getPnt();
    int getWidth();
    int getHeight();
    QRect toQtRect();
};

#endif // RECTANGLE_H
