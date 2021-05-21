#include "TransformObjectVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModel.h"
TransformObjectVisitor::TransformObjectVisitor(Matrix<double> &transformMatrix)
{
    this->transformMatrix = transformMatrix;
}

void TransformObjectVisitor::visitPoint(Point& point)
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
void TransformObjectVisitor::visitEdge(Edge& edge)
{
    std::shared_ptr<BaseVisitor> visitor(new TransformObjectVisitor(transformMatrix));

    edge.getStart()->accept(visitor);
    edge.getFinish()->accept(visitor);

}
void TransformObjectVisitor::visitCamera(BaseCamera& camera)
{
    Matrix<double>cam_matr = camera.getDirection().transformMatrix;
    cam_matr *= transformMatrix;
    direction dir = {camera.getDirection().distance, Matrix<double>(cam_matr)};
    camera.setDirection(dir);
}
