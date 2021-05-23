//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_MOVECAMERACOMMAND_H
#define LAB_03_MOVECAMERACOMMAND_H


#include "BaseCommand.h"
#include "Model/Handlers/MoveCameraHandler.h"
class MoveCameraCommand : public BaseCommand
{
public:
    MoveCameraCommand(double dx, double dy, double dz);
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker) override;

protected:
    double dx, dy, dz;
};

#endif //LAB_03_MOVECAMERACOMMAND_H
