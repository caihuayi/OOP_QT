#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H
#include "graphfactory.h"
#include "rectangle.h"
class RectangleFactory : public GraphFactory
{
public:
    Graph* create() override;
};

#endif // RECTANGLEFACTORY_H
