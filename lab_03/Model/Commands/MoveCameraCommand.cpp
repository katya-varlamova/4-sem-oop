//
// Created by Екатерина on 16.05.2021.
//

#include "MoveCameraCommand.h"
MoveCameraCommand::MoveCameraCommand(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveCameraCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    MoveCameraHandler mh(dx, dy, dz);
    mh.handle(scene);
}