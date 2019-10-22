#include "triangle.h"
using namespace std;
Triangle::Triangle()
{

}

Triangle::~Triangle()
{

}

void Triangle::begPoint(double x, double y)
{
    Graph::begPoint(x, y);
    this->point[0].setX(x);
    this->point[0].setY(y);
    this->point[2].setX(x);
}

void Triangle::Create(double x, double y)
{
    this->point[1].setX(x);
    this->point[1].setY(y);
    this->point[2].setY(y);
}

void Triangle::OnPress(double x, double y)
{
    if (x >= point[0].rx() && x <= point[1].rx()
            && y >= point[0].ry() && y <= point[1].ry()
            && (y-point[0].ry())/(x-point[0].rx()) >=
            (point[0].ry()-point[1].ry())/(point[0].rx()-point[1].rx()))
    {
        active = true;
    }
    cout << "active=" << active << endl;
}

void Triangle::OnMove(double cx, double cy)
{
    if (active == true)
    {
        point[0].setX(point[0].rx()+cx);
        point[0].setY(point[0].ry()+cy);
        point[1].setX(point[1].rx()+cx);
        point[1].setY(point[1].ry()+cy);
        point[2].setX(point[2].rx()+cx);
        point[2].setY(point[2].ry()+cy);
    }
}

void Triangle::Draw(QPainter &painter)
{
    painter.drawPolygon(point, 3, Qt::OddEvenFill);
}
