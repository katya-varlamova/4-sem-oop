//
// Created by Екатерина on 16.05.2021.
//

#ifndef LAB_03_UNDOCOMMAND_H
#define LAB_03_UNDOCOMMAND_H

#include "BaseCommand.h"
class UndoCommand : public BaseCommand
{
public:
    UndoCommand() = default;
    virtual void execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> caretaker) override;
};

#endif //LAB_03_UNDOCOMMAND_H
