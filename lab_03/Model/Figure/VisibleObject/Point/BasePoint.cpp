#include "BasePoint.h"

BasePoint::BasePoint(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
double BasePoint::getX()
{
    return x;
}

void BasePoint::setX(double x)
{
    this->x = x;
}

double BasePoint::getY()
{
    return y;
}

void BasePoint::setY(double y)
{
    this->y = y;
}

double BasePoint::getZ()
{
    return z;
}

void BasePoint::setZ(double z)
{
    this->z = z;
}
bool BasePoint::isComposite()
{
    return false;
}
