#include "MoveCameraHandler.h"
MoveCameraHandler::MoveCameraHandler(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveCameraHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    scene->getCamera()->setOffset(std::vector<double>({dx + scene->getCamera()->getOffset()[0],
                                                       dy + scene->getCamera()->getOffset()[1],
                                                       dz + scene->getCamera()->getOffset()[2]}));
}