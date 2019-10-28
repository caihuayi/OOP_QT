#include "line.h"
using namespace std;
Line::Line()
{

}

Line::~Line()
{

}

void Line::begPoint(double x, double y)
{
    Graph::begPoint(x, y);
    point1.setX(x);
    point1.setY(y);
}

void Line::Create(double x, double y)
{
    point2.setX(x);
    point2.setY(y);
}

void Line::OnPress(double x, double y)
{
    if (isIn(x, y))
    {
        active = true;
    }
    cout << "active=" << active << endl;
}

void Line::OnMove(double cx, double cy)
{
    if (active == true)
    {
        point1.setX(point1.rx()+cx);
        point1.setY(point1.ry()+cy);
        point2.setX(point2.rx()+cx);
        point2.setY(point2.ry()+cy);
    }
}

void Line::Draw(QPainter &painter)
{
    painter.drawLine(point1, point2);
}

bool Line::isIn(double x, double y)
{
    return x >= point1.rx() && x <= point2.rx()
            && y >= point1.ry() && y <= point2.ry()
            && (y-point1.ry())/(x-point1.rx()) >=
            (point1.ry()-point2.ry())/(point1.rx()-point2.rx())-10
            && (y-point1.ry())/(x-point1.rx()) <=
            (point1.ry()-point2.ry())/(point1.rx()-point2.rx())+10;
}

QTextStream& Line::write_file(QTextStream &out)
{
    out << 4 << " " << point1.rx() << " " << point1.ry() << " " << point2.rx() << " " << point2.ry() << " ";
    Graph::write_file(out);

    return out;
}

QTextStream& Line::read_file(QTextStream &in)
{
    int x1, x2, y1, y2;
    in >> x1 >> y1 >> x2 >> y2;
    Graph::read_file(in);
    point1.setX(x1);
    point1.setY(y1);
    point2.setX(x2);
    point2.setY(y2);

    return in;
}
