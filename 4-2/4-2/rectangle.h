#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "graph.h"

class Rectangle : public Graph
{
public:
    Rectangle();
    ~Rectangle() override;
    void Create(double x, double y) override;
    void OnPress(double x, double y) override;
    void OnMove(double cx, double cy) override;
    void Draw(QPainter&) override;
private:
    double height;
    double width;
};

#endif // RECTANGLE_H
