#ifndef MOVEOBJECTHANDLER_H
#define MOVEOBJECTHANDLER_H

#include "BaseHandler.h"
class MoveObjectHandler : public BaseHandler
{
public:
    MoveObjectHandler(double dx, double dy, double dz);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    double dx, dy, dz;
};

#endif // MOVEOBJECTHANDLER_H
