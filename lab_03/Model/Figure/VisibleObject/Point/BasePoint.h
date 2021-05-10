#ifndef BASEPOINT_H
#define BASEPOINT_H

#include "Model/Figure/VisibleObject/VisibleObject.h"
class BasePoint : public VisibleObject
{
public:
    BasePoint(double x, double y, double z, std::vector<double> offset = {0, 0, 0});

    double getX();
    double getY();
    double getZ();
    std::vector<double>  getOffset();

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    void setOffset(std::vector<double> offset);

    virtual bool isComposite() override;
protected:
    double x, y, z;
    std::vector<double> worldOffset;

};

#endif // BASEPOINT_H
