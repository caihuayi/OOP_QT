#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H
#include "graphfactory.h"
#include "triangle.h"
class TriangleFactory : public GraphFactory
{
public:
    Graph * create() override;
};

#endif // TRIANGLEFACTORY_H
