#ifndef MOVECAMERAHANDLER_H
#define MOVECAMERAHANDLER_H

#include "BaseHandler.h"
class MoveCameraHandler : public BaseHandler
{
public:
    MoveCameraHandler(double dx, double  dy, double dz);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    double dx, dy, dz;
};

#endif // MOVECAMERAHANDLER_H
