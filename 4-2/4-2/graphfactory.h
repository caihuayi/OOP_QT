#ifndef GRAPHFACTORY_H
#define GRAPHFACTORY_H
#include "graph.h"

class GraphFactory
{
public:
    virtual Graph* create() = 0;
    virtual ~GraphFactory() = default;
};

#endif // GRAPHFACTORY_H
