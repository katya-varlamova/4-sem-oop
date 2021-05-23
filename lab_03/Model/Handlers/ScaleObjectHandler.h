#ifndef SCALEOBJECTHANDLER_H
#define SCALEOBJECTHANDLER_H

#include "BaseHandler.h"
class ScaleObjectHandler : public BaseHandler
{
public:
    ScaleObjectHandler(double kx, double  ky, double kz);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    double kx, ky, kz;
};

#endif // SCALEOBJECTHANDLER_H
