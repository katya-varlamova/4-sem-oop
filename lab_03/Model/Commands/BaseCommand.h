//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_BASECOMMAND_H
#define LAB_03_BASECOMMAND_H

#include "Model/Scene/BaseScene.h"
#include "Model/Snapshots/Caretaker.h"
class BaseCommand
{
public:
    BaseCommand() = default;
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker) = 0;

};


#endif //LAB_03_BASECOMMAND_H
