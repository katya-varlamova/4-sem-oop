#include "Point.h"

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}
double Point::getX()
{
    return x;
}

void Point::setX(double x)
{
    this->x = x;
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
std::shared_ptr<Point> Point::clone()
{
    return std::shared_ptr<Point>(new Point(x, y, z));
}
void Point::transform(Matrix<double> &transformMatrix)
{
    Matrix<double>str({ {x},
                        {y},
                        {z},
                        {1} });
    Matrix<double>res = transformMatrix * str;
    x = res[0][0];
    y = res[1][0];
    z = res[2][0];
}