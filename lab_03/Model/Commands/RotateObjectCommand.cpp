//
// Created by Екатерина on 16.05.2021.
//

#include "RotateObjectCommand.h"
RotateObjectCommand::RotateObjectCommand(double ax, double ay, double az)
{
    this->ax = ax;
    this->ay = ay;
    this->az = az;
}
void RotateObjectCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> caretaker)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    RotateObjectHandler rh(ax, ay, az);
    rh.handle(scene);
}