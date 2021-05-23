//
// Created by Екатерина on 09.05.2021.
//

#include "DrawHandler.h"
DrawHandler::DrawHandler(std::shared_ptr<BaseDrawer> &drawer)
{
    this->drawer = drawer;
}
void DrawHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    std::shared_ptr<BaseVisitor> visitor(new DrawObjectVisitor(drawer));
    for (auto &obj : *scene)
    {
        obj->accept(visitor);
    }
}