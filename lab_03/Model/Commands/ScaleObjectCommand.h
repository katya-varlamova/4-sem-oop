//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_SCALEOBJECTCOMMAND_H
#define LAB_03_SCALEOBJECTCOMMAND_H

#include "BaseCommand.h"
#include "Model/Handlers/ScaleObjectHandler.h"
class ScaleObjectCommand : public BaseCommand
{
public:
    ScaleObjectCommand(double kx, double ky, double kz);
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker) override;

protected:
    double kx, ky, kz;
};

#endif //LAB_03_SCALEOBJECTCOMMAND_H
