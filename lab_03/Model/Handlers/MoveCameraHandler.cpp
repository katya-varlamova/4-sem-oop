#include "MoveCameraHandler.h"
MoveCameraHandler::MoveCameraHandler(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveCameraHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    std::shared_ptr<BaseVisitor> visitor( new MoveObjectVisitor(dx, dy, dz));
    scene->getCamera()->accept(visitor);
}