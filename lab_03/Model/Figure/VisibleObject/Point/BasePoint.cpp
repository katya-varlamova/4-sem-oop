#include "BasePoint.h"

BasePoint::BasePoint(double x, double y, double z, std::vector<double> offset)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->worldOffset = offset;
}
double BasePoint::getX()
{
    return x;
}

void BasePoint::setX(double x)
{
    this->x = x;
}
std::vector<double> BasePoint::getOffset()
{
    return worldOffset;
}

void BasePoint::setOffset(std::vector<double> offset)
{
    this->worldOffset = offset;
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
