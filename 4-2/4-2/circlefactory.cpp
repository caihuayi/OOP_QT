#include "circlefactory.h"

Graph* CircleFactory::create()
{
    return new Circle();
}
