#include "Point.h"

Point::Point(double x, double y, double z) : BasePoint(x, y, z) {};

void Point::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    visitor->visitPoint(*this);
}

std::shared_ptr<BaseObject> Point::clone()
{
    return std::shared_ptr<BaseObject>(new Point(x, y, z));
}
