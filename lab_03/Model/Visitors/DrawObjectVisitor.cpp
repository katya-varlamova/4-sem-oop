//
// Created by Екатерина on 09.05.2021.
//

#include "DrawObjectVisitor.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModel.h"
DrawObjectVisitor::DrawObjectVisitor(std::shared_ptr<BaseDrawer>& drawer)
{
    this->drawer = drawer;
}
void DrawObjectVisitor::visitEdge(Edge &edge)
{
    drawer->drawLine(edge.getStart()->getX(), edge.getStart()->getY(),
                      edge.getFinish()->getX(), edge.getFinish()->getY());
}
void DrawObjectVisitor::visitPoint(Point &point)
{
    drawer->drawPoint(point.getX(), point.getY());
}
void DrawObjectVisitor::visitCamera(BaseCamera &camera)
{
}
