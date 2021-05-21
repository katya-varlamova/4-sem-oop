#include "BaseObject.h"
std::vector<double> BaseObject::getOffset()
{
    return worldOffset;
}
void BaseObject::setOffset(std::vector<double> offset)
{
    this->worldOffset = offset;
}