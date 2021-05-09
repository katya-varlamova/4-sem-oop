#ifndef BASEPOINT_H
#define BASEPOINT_H

#include "Model/Figure/VisibleObject/VisibleObject.h"
class BasePoint : public VisibleObject
{
public:
    BasePoint(double x, double y, double z);

    double getX();
    double getY();
    double getZ();

    void setX(double x);
    void setY(double y);
    void setZ(double z);

    virtual bool isComposite() override;
protected:
    double x, y, z;

};

#endif // BASEPOINT_H
