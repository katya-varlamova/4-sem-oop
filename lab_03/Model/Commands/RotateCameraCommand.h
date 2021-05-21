//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_ROTATECAMERACOMMAND_H
#define LAB_03_ROTATECAMERACOMMAND_H

#include "BaseCommand.h"
#include "Model/Handlers/RotateCameraHandler.h"
class RotateCameraCommand  : public BaseCommand
{
public:
    RotateCameraCommand (double ax, double ay, double az);
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> caretaker) override;

protected:
    double ax, ay, az;
};

#endif //LAB_03_ROTATECAMERACOMMAND_H
