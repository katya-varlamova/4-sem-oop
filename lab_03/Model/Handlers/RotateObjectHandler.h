#ifndef ROTATEOBJECTHANDLER_H
#define ROTATEOBJECTHANDLER_H

#include "BaseHandler.h"
#include <math.h>
class RotateObjectHandler : public BaseHandler
{
public:
    RotateObjectHandler(double ax, double ay, double az);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    double ax;
    double ay;
    double az;
};

#endif // ROTATEOBJECTHANDLER_H
