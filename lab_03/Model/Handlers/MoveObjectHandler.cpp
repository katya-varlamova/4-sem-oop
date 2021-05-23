#include "MoveObjectHandler.h"

MoveObjectHandler::MoveObjectHandler(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveObjectHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    for (auto &obj : *scene) {
        obj->setOffset(std::vector<double>({dx + obj->getOffset()[0],
                                                           dy + obj->getOffset()[1],
                                                           dz + obj->getOffset()[2]}));
    }

}
