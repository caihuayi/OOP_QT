#ifndef CIRCLEFACTORY_H
#define CIRCLEFACTORY_H
#include "graphfactory.h"
#include "circle.h"

class CircleFactory : public GraphFactory
{
public:
    Graph * create() override;
};

#endif // CIRCLEFACTORY_H
