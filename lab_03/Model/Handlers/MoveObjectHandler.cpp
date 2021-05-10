#include "MoveObjectHandler.h"

MoveObjectHandler::MoveObjectHandler(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveObjectHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    std::shared_ptr<BaseVisitor> visitor( new MoveObjectVisitor(dx, dy, dz));
    for (auto &obj : *scene)
        obj->accept(visitor);

}
