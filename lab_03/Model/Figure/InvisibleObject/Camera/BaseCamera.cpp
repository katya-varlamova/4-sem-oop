#include "BaseCamera.h"

void BaseCamera::setDirection(direction &direction)
{
    this->dir = direction;
}
direction BaseCamera::getDirection()
{
    return dir;
}
bool BaseCamera::BaseCamera::isComposite()
{
    return true;
}
