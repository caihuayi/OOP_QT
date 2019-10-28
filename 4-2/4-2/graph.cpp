#include "graph.h"
using namespace std;
Graph::Graph()
{
    exist = false;
}

Graph::~Graph()
{

}

bool Graph::get_exist()
{
    return exist;
}

bool Graph::get_active()
{
    return active;
}

void Graph::set_active(bool b)
{
    active = b;
}

QTextStream& Graph::write_file(QTextStream &out)
{
    out << base_point.rx() << " " << base_point.ry() << " " << old_x << " " << old_y << endl;

    return out;
}

QTextStream& Graph::read_file(QTextStream& in)
{
    double x, y;
    in >> x >> y >> old_x >> old_y;
    base_point.setX(x);
    base_point.setY(y);

    return in;
}

void Graph::begPoint(double x, double y)
{
    base_point.setX(x);
    base_point.setY(y);
}

void Graph::OnRelease(double x, double y)
{
    exist = true;
    old_x = x;
    old_y = y;
}
