//
// Created by Екатерина on 09.05.2021.
//

#include "ProjectionVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModel.h"
ProjectionVisitor::ProjectionVisitor(std::shared_ptr<BaseCamera> &camera)
{
    this->camera = camera;
}
void ProjectionVisitor::visit(FrameModel &model)
{
    for (auto &point : model.primitives->getPoints()) {
        Matrix<double> pointMatrix = {{point->getX()},
                                      {point->getY()},
                                      {point->getZ()},
                                      {1}};
        Matrix<double> res = camera->getDirection().transformMatrix * pointMatrix;

        res[0][0] += model.getOffset()[0] - camera->getOffset()[0];
        res[1][0] += model.getOffset()[1] - camera->getOffset()[1];
        res[2][0] += model.getOffset()[2] - camera->getOffset()[2];

        point->setX(res[0][0]);
        point->setY(res[1][0]);
        point->setZ(res[2][0]);

        double cameraPosZ = camera->getOffset()[2];
        double planeZ = camera->getOffset()[2] - camera->getDirection().distance;
        point->setX(point->getX() * (cameraPosZ - planeZ) / (cameraPosZ - point->getZ()));
        point->setY(point->getY() * (cameraPosZ - planeZ) / (cameraPosZ - point->getZ()));
        point->setZ(point->getZ() - planeZ);
    }
}
void ProjectionVisitor::visit(CompositeObject &compositeObject)
{
    std::shared_ptr<BaseVisitor>ptr(this);
    for (auto &obj : compositeObject)
        obj->accept(ptr);
}
void ProjectionVisitor::visit(BaseCamera &camera)
{

}