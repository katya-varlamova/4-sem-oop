//
// Created by Екатерина on 16.05.2021.
//

#include "MoveObjectCommand.h"
MoveObjectCommand::MoveObjectCommand(double dx, double dy, double dz)
{
    this->dx = dx;
    this->dy = dy;
    this->dz = dz;
}
void MoveObjectCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    MoveObjectHandler mh(dx, dy, dz);
    mh.handle(scene);
}