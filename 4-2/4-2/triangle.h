#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <graph.h>

class Triangle : public Graph
{
public:
    Triangle();
    ~Triangle() override;
    void Create(double x, double y) override;
    void OnPress(double x, double y) override;
    void OnMove(double cx, double cy) override;
    void Draw(QPainter&) override;
    void begPoint(double x, double y) override;
    bool isIn(double x, double y) override;
private:
    QPointF point[3];
};

#endif // TRIANGLE_H
