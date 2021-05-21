#include "Point.h"

Point::Point(double x, double y, double z, std::vector<double> offset)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->worldOffset = offset;
}
Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    this->worldOffset = point.worldOffset;
}
double Point::getX()
{
    return x;
}

void Point::setX(double x)
{
    this->x = x;
}
std::vector<double> Point::getOffset()
{
    return worldOffset;
}

void Point::setOffset(std::vector<double> offset)
{
    this->worldOffset = offset;
}
double Point::getY()
{
    return y;
}

void Point::setY(double y)
{
    this->y = y;
}

double Point::getZ()
{
    return z;
}

void Point::setZ(double z)
{
    this->z = z;
}
void Point::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    visitor->visitPoint(*this);
}

std::shared_ptr<Point> Point::clone()
{
    return std::shared_ptr<Point>(new Point(x, y, z, this->worldOffset));
}
