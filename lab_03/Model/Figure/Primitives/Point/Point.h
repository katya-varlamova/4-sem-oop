#ifndef Point_H
#define Point_H

#include "Model/Figure/VisibleObject/VisibleObject.h"
#include "Model/Containers/matrix/matrix/matrix.h"
class Point
{
public:
    Point(double x, double y, double z);
    Point(const Point &point);
    double getX();
    double getY();
    double getZ();

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void transform(Matrix<double> &transformMatrix);

    std::shared_ptr<Point> clone();
protected:
    double x, y, z;

};

#endif // Point_H
