//
// Created by Екатерина on 16.05.2021.
//

#include "DrawCommand.h"
DrawCommand::DrawCommand(std::shared_ptr<BaseDrawer> &drawer)
{
    this->drawer = drawer;
}
void DrawCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker)
{
    std::shared_ptr<BaseScene> copyScene(new Scene(scene));

    ProjectionHandler ph;
    ph.handle(copyScene);

    DrawHandler dh(drawer);
    dh.handle(copyScene);
}