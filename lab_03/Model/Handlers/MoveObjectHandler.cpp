#include "MoveObjectHandler.h"

MoveObjectHandler::MoveObjectHandler(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveObjectHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    Matrix<double> transMatr = {{1, 0, 0, dx},
                                {0, 1, 0, dy},
                                {0, 0, 1, dz},
                                {0, 0, 0,  1}};
    std::shared_ptr<BaseVisitor> visitor( new TransformObjectVisitor(transMatr));
    for (auto &obj : *scene)
        obj->accept(visitor);

}
