//
// Created by Екатерина on 10.05.2021.
//

#include "MoveObjectVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModel.h"
MoveObjectVisitor::MoveObjectVisitor(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveObjectVisitor::visitCamera(BaseCamera& camera)
{
    camera.setOffset(std::vector<double>({dx + camera.getOffset()[0],
                                            dy + camera.getOffset()[1],
                                            dz + camera.getOffset()[2]}));
}
void MoveObjectVisitor::visitPoint(Point& point)
{
    point.setOffset(std::vector<double>({point.getOffset()[0] + dx,
                                         point.getOffset()[1] + dy,
                                         point.getOffset()[2] + dz}));
}
void MoveObjectVisitor::visitEdge(Edge& edge)
{
    std::shared_ptr<BaseVisitor> visitor ( new MoveObjectVisitor(dx, dy, dz));
    edge.getStart()->accept(visitor);
    edge.getFinish()->accept(visitor);
}