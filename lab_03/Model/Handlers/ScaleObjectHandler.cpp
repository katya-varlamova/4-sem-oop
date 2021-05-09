#include "ScaleObjectHandler.h"

ScaleObjectHandler::ScaleObjectHandler(double kx, double  ky, double kz)
{
    this->kx = kx;
    this->ky = ky;
    this->kz = kz;
}
void ScaleObjectHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    Matrix<double> transMatr = {{kx, 0, 0, 0},
                                {0, ky, 0, 0},
                                {0, 0, kz, 0},
                                {0, 0, 0,  1}};
    std::shared_ptr<BaseVisitor> visitor( new TransformObjectVisitor(transMatr));
    for (auto &obj : *scene)
        obj->accept(visitor);
}