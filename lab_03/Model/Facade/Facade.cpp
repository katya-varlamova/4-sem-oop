#include "Facade.h"
Facade::Facade()
{
    this->caretaker = std::shared_ptr<Caretaker>(new Caretaker);
}
void Facade::executeCommand(BaseCommand &command)
{
    command.execute(scene, caretaker);
}