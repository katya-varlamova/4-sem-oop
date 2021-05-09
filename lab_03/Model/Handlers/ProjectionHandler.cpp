//
// Created by Екатерина on 09.05.2021.
//

#include "ProjectionHandler.h"
void ProjectionHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    std::shared_ptr<BaseVisitor> visitor(new ProjectionVisitor(scene->getCamera()));

    for (auto &obj : *scene)
    {
        obj->accept(visitor);
    }
}