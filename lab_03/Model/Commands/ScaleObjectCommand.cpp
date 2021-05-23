//
// Created by Екатерина on 16.05.2021.
//

#include "ScaleObjectCommand.h"
ScaleObjectCommand::ScaleObjectCommand(double kx, double ky, double kz)
{
    this->kx = kx;
    this->ky = ky;
    this->kz = kz;
}
void ScaleObjectCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker)
{
    caretaker->addSnapshot(scene->makeSnapshot());
    ScaleObjectHandler sh(kx, ky, kz);
    sh.handle(scene);
}