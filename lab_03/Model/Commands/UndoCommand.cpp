
#include "UndoCommand.h"
void UndoCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> caretaker)
{
    std::shared_ptr<Snapshot> shot = caretaker->popSnapshot();
    if (!shot)
        return;
    scene->restore(shot);
}