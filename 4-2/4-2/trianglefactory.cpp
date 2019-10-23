#include "trianglefactory.h"

Graph* TriangleFactory::create()
{
    return new Triangle();
}
