#include "TransformObjectVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/VisibleObject/Point/Point.h"
#include "Model/Figure/VisibleObject/Edge/Edge.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.h"
TransformObjectVisitor::TransformObjectVisitor(Matrix<double> &transformMatrix)
{
    this->transformMatrix = transformMatrix;
}

void TransformObjectVisitor::visitPoint(BasePoint& point)
{
    Matrix<double>str({ {point.getX()},
                        {point.getY()},
                        {point.getZ()},
                        {1} });
    Matrix<double>res = transformMatrix * str;
    point.setX(res[0][0]);
    point.setY(res[1][0]);
    point.setZ(res[2][0]);
}
void TransformObjectVisitor::visitEdge(BaseEdge& edge)
{
    std::shared_ptr<BaseVisitor> visitor(new TransformObjectVisitor(transformMatrix));

    edge.getStart()->accept(visitor);
    edge.getFinish()->accept(visitor);

}
void TransformObjectVisitor::visitFrameModel(FrameModel &model)
{
    std::shared_ptr<BaseVisitor> visitor(new TransformObjectVisitor(transformMatrix));
    for (auto& obj : model)
    {
        obj->accept(visitor);
    }
}
void TransformObjectVisitor::visitCamera(BaseCamera& camera)
{
    Matrix<double>cam_matr = camera.getTransformMatrix();
    cam_matr *= transformMatrix;
    camera.setTransformMatrix(cam_matr);
}
