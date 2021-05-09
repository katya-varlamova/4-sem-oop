//
// Created by Екатерина on 09.05.2021.
//

#include "DrawObjectVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/VisibleObject/Point/Point.h"
#include "Model/Figure/VisibleObject/Edge/Edge.h"
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.h"
DrawObjectVisitor::DrawObjectVisitor(std::shared_ptr<BaseDrawer>& drawer)
{
    this->drawer = drawer;
}
void DrawObjectVisitor::visitCamera(BaseCamera &camera)
{
}

void DrawObjectVisitor::visitEdge(BaseEdge &edge)
{
//    std::cout << edge.getStart()->getX() << " "
//    << edge.getStart()->getY() << " "
//    << edge.getFinish()->getX() << " "
//    << edge.getFinish()->getY() << std::endl;

    drawer->drawLine(edge.getStart()->getX(), edge.getStart()->getY(),
                      edge.getFinish()->getX(), edge.getFinish()->getY());
}
void DrawObjectVisitor::visitFrameModel(FrameModel &model)
{
    std::shared_ptr<BaseVisitor> visitor (new DrawObjectVisitor(drawer));
    for (auto &obj : model)
        obj->accept(visitor);

}
void DrawObjectVisitor::visitPoint(BasePoint &point)
{
//    std::cout << "point: "<< point.getX() << " "
//              << point.getY() << std::endl;
    drawer->drawPoint(point.getX(), point.getY());
}