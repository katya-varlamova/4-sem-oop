//
// Created by Екатерина on 10.05.2021.
//

#include "MoveObjectVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/VisibleObject/Point/Point.h"
#include "Model/Figure/VisibleObject/Edge/Edge.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.h"
MoveObjectVisitor::MoveObjectVisitor(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveObjectVisitor::visitFrameModel(FrameModel &model)
{
    std::shared_ptr<BaseVisitor> visitor ( new MoveObjectVisitor(dx, dy, dz));
    for (auto & obj : model)
        obj->accept(visitor);
}
void MoveObjectVisitor::visitCamera(BaseCamera& camera)
{
    camera.setPosition(std::vector<double>({dx + camera.getPosition()[0],
                                            dy + camera.getPosition()[1],
                                            dz + camera.getPosition()[2]}));
}
void MoveObjectVisitor::visitPoint(BasePoint& point)
{
    point.setOffset(std::vector<double>({point.getOffset()[0] + dx,
                                         point.getOffset()[1] + dy,
                                         point.getOffset()[2] + dz}));
}
void MoveObjectVisitor::visitEdge(BaseEdge& edge)
{
    std::shared_ptr<BaseVisitor> visitor ( new MoveObjectVisitor(dx, dy, dz));
    edge.getStart()->accept(visitor);
    edge.getFinish()->accept(visitor);
}