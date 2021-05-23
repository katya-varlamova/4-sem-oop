//
// Created by Екатерина on 09.05.2021.
//

#ifndef LAB_03_PROJECTIONHANDLER_H
#define LAB_03_PROJECTIONHANDLER_H

#include "BaseHandler.h"
#include "Model/Visitors/ProjectionVisitor.h"
class ProjectionHandler : public BaseHandler
{
public:
    ProjectionHandler() = default;
    void handle(std::shared_ptr<BaseScene> &scene) override;
};


#endif //LAB_03_PROJECTIONHANDLER_H
