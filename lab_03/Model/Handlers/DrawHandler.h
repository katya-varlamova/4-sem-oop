//
// Created by Екатерина on 09.05.2021.
//

#ifndef LAB_03_DRAWHANDLER_H
#define LAB_03_DRAWHANDLER_H
#include "BaseHandler.h"
#include "Drawer/BaseDrawer.h"
#include "Model/Visitors/DrawObjectVisitor.h"
class DrawHandler : public BaseHandler
{
public:
    DrawHandler(std::shared_ptr<BaseDrawer>& drawer);
    void handle(std::shared_ptr<BaseScene> &scene) override;

protected:
    std::shared_ptr<BaseDrawer> drawer;
};


#endif //LAB_03_DRAWHANDLER_H
