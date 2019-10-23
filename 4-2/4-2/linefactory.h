#ifndef LINEFACTORY_H
#define LINEFACTORY_H
#include "graphfactory.h"
#include "line.h"

class LineFactory : public GraphFactory
{
public:
    Graph* create() override;
};

#endif // LINEFACTORY_H
