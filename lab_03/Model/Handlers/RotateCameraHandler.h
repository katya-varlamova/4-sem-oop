#ifndef ROTATECAMERAHANDLER_H
#define ROTATECAMERAHANDLER_H

#include "BaseHandler.h"
#include "math.h"
class RotateCameraHandler : public BaseHandler
{
public:
    RotateCameraHandler(double ax, double ay, double az);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    double ax, ay, az;
};

#endif // ROTATECAMERAHANDLER_H
