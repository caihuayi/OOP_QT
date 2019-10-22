#include "circle.h"
using namespace std;
Circle::Circle()
{

}

Circle::~Circle()
{

}


void Circle::Create(double x, double y)
{
    diameter = sqrt((x-base_point.rx())*(x-base_point.rx())+(y-base_point.ry())*(y-base_point.ry()));
}

void Circle::OnPress(double x, double y)
{
    if (isIn(x, y))
    {
        active = true;
    }
    else
    {
        active = false;
    }
}

void Circle::OnMove(double cx, double cy)
{
    if (active == true)
    {
        //double x = base_point.rx();
        //double y = base_point.ry();
        cout << "active == true" << endl;
        base_point.setX(base_point.rx()+cx);
        base_point.setY(base_point.ry()+cy);
    }
}

bool Circle::isIn(double x, double y)
{
    double displacement = sqrt((x-base_point.rx())*(x-base_point.rx())+(y-base_point.ry())*(y-base_point.ry()));
    return displacement <= diameter;
}


QPointF Circle::get_base_point()
{
    return base_point;
}

qreal Circle::get_diameter()
{
    return diameter;
}


void Circle::Draw(QPainter &painter)
{
    painter.drawEllipse(this->get_base_point(), this->get_diameter(), this->get_diameter());
}
