//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_DRAWCOMMAND_H
#define LAB_03_DRAWCOMMAND_H

#include "BaseCommand.h"
#include "Drawer/BaseDrawer.h"
#include "Model/Handlers/DrawHandler.h"
#include "Model/Handlers/ProjectionHandler.h"

class DrawCommand : public BaseCommand
{
public:
    DrawCommand(std::shared_ptr<BaseDrawer>& drawer);
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> caretaker) override;

protected:
    std::shared_ptr<BaseDrawer> drawer;
};


#endif //LAB_03_DRAWCOMMAND_H
