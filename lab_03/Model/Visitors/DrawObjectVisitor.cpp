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
void DrawObjectVisitor::visit(FrameModel &model)
{
    for (auto &point : model.primitives->getPoints())
        drawer->drawPoint(point->getX(), point->getY());
    for (auto &edge : model.primitives->getEdges())
        drawer->drawLine(model.primitives->getPoints()[edge->getStart()]->getX(),
                         model.primitives->getPoints()[edge->getStart()]->getY(),
                         model.primitives->getPoints()[edge->getFinish()]->getX(),
                         model.primitives->getPoints()[edge->getFinish()]->getY());
}
void DrawObjectVisitor::visit(CompositeObject &compositeObject)
{
    std::shared_ptr<BaseVisitor>ptr(this);
    for (auto &obj : compositeObject)
        obj->accept(ptr);
}
void DrawObjectVisitor::visit(BaseCamera &camera)
{

}