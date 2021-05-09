#ifndef POINT_H
#define POINT_H

#include <memory>
#include "Model/Figure/VisibleObject/Point/BasePoint.h"
class Point final: public BasePoint
{
public:
    Point(double x, double y, double z);

    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;
};

#endif // POINT_H
