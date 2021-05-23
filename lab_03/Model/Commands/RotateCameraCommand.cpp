//
// Created by Екатерина on 16.05.2021.
//

#include "RotateCameraCommand.h"
RotateCameraCommand::RotateCameraCommand(double ax, double ay, double az)
{
    this->ax = ax;
    this->ay = ay;
    this->az = az;
}
void RotateCameraCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    RotateCameraHandler rh(ax, ay, az);
    rh.handle(scene);
}