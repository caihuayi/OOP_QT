#ifndef CIRCLE_H
#define CIRCLE_H
#include "graph.h"
#include <qmath.h>
#include <iostream>

class Circle :  public Graph
{
public:
    Circle();
    ~Circle() override;
    void Create(double x, double y) override;
    void OnPress(double x, double y) override;
    void OnMove(double x, double y) override;
    void Draw(QPainter&) override;
    bool isIn(double x, double y) override;
    QTextStream& write_file(QTextStream&) override;
    QTextStream& read_file(QTextStream&) override;
    QPointF get_base_point();
    qreal get_diameter();
private:
    qreal diameter;
};

#endif // CIRCLE_H
