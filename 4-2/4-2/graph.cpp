#include "graph.h"

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

