#ifndef Point_H
#define Point_H

#include "Model/Figure/VisibleObject/VisibleObject.h"
class Point
{
public:
    Point(double x, double y, double z, std::vector<double> offset = {0, 0, 0});
    Point(const Point &point);
    double getX();
    double getY();
    double getZ();
    std::vector<double>  getOffset();

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setOffset(std::vector<double> offset);

    void accept(std::shared_ptr<BaseVisitor>& visitor);
    std::shared_ptr<Point> clone();
protected:
    double x, y, z;
    std::vector<double> worldOffset;

};

#endif // Point_H
