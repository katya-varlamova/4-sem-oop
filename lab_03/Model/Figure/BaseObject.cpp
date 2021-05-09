#include "BaseObject.h"
#include <iostream>
void BaseObject::setWorldPosition(std::vector<double> pos)
{
    worldPosition = pos;
}
std::vector<double> BaseObject::getWorldPosition()
{
    return worldPosition;
}
