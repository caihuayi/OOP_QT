#ifndef GRAPH_H
#define GRAPH_H
#include <QPainter>
#include <QTextStream>
#include <iostream>
class Graph
{
public:
    Graph();
    virtual ~Graph();
    virtual void Create(double x, double y) = 0;
    virtual void OnPress(double x, double y) = 0;
    virtual void OnMove(double x, double y) = 0;
    virtual void Draw(QPainter&) = 0;
    virtual bool isIn(double x, double y) = 0;

    virtual QTextStream& write_file(QTextStream&);
    virtual QTextStream& read_file(QTextStream&);
    virtual void begPoint(double x, double y);
    void OnRelease(double x, double y);
    bool get_exist();
    bool get_active();
    void set_active(bool b);

    double old_x;
    double old_y;
protected:
    QPointF base_point;
    bool exist;
    bool active;
};

#endif // GRAPH_H
