#include "rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::~Rectangle()
{

}


void Rectangle::Create(double x, double y)
{
    width = x-base_point.rx();
    height = y-base_point.ry();
}

void Rectangle::OnPress(double x, double y)
{
    if (x >= base_point.rx() && x <= base_point.rx()+width
            && y >= base_point.ry() && y <= base_point.ry()+height)
    {
        active = true;
    }
    else
    {
        active = false;
    }
}

void Rectangle::OnMove(double cx, double cy)
{
    if (active == true)
    {
        base_point.setX(base_point.rx()+cx);
        base_point.setY(base_point.ry()+cy);
    }
}



void Rectangle::Draw(QPainter &painter)
{
    painter.drawRect(base_point.rx(), base_point.ry(), width, height);
}
