#include "rectanglefactory.h"

Graph* RectangleFactory::create()
{
    return new Rectangle();
}
