#ifndef LINE_H
#define LINE_H
#include "graph.h"

class Line : public Graph
{
public:
    Line();
    ~Line() override;
    void Create(double x, double y) override;
    void OnPress(double x, double y) override;
    void OnMove(double cx, double cy) override;
    void Draw(QPainter &) override;
    void begPoint(double x, double y) override;
    bool isIn(double x, double y) override;
    QTextStream& write_file(QTextStream&) override;
    QTextStream& read_file(QTextStream&) override;
private:
    QPointF point1;
    QPointF point2;
};

#endif // LINE_H
