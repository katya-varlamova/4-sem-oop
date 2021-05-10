//
// Created by Екатерина on 09.05.2021.
//

#include "ProjectionVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/VisibleObject/Point/Point.h"
#include "Model/Figure/VisibleObject/Edge/Edge.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.h"
ProjectionVisitor::ProjectionVisitor(std::shared_ptr<BaseCamera> &camera)
{
    this->camera = camera;
}
void ProjectionVisitor::visitPoint(BasePoint &point)
{
    Matrix<double> pointMatrix = {{point.getX()},
                                  {point.getY()},
                                  {point.getZ()},
                                  {1} };
    Matrix<double> res = camera->getTransformMatrix() * pointMatrix;

    res[0][0] += point.getOffset()[0] - camera->getPosition()[0];
    res[1][0] += point.getOffset()[1] - camera->getPosition()[1];
    res[2][0] += point.getOffset()[2] - camera->getPosition()[2];

    point.setX(res[0][0]);
    point.setY(res[1][0]);
    point.setZ(res[2][0]);

    double cameraPosZ = camera->getPosition()[2];
    double planeZ = camera->getPosition()[2] - camera->getDistance();
    point.setX(point.getX() * (cameraPosZ - planeZ) / (cameraPosZ - point.getZ()));
    point.setY(point.getY() * (cameraPosZ - planeZ) / (cameraPosZ - point.getZ()));
    point.setZ(point.getZ()  - planeZ);
}
void ProjectionVisitor::visitFrameModel(FrameModel &model)
{
    std::shared_ptr<BaseVisitor> visitor(new ProjectionVisitor(camera));
    for (auto& obj : model)
    {
        obj->accept(visitor);
    }
}
void ProjectionVisitor::visitEdge(BaseEdge &edge)
{
    std::shared_ptr<BaseVisitor> visitor(new ProjectionVisitor(camera));
    edge.getStart()->accept(visitor);
    edge.getFinish()->accept(visitor);

}
void ProjectionVisitor::visitCamera(BaseCamera &camera)
{

}