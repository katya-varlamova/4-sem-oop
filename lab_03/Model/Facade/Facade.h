#ifndef FACADE_H
#define FACADE_H

#include "Model/Scene/Scene.h"
#include "Model/Scene/SceneBuilder/SceneBuilder.h"
#include "Model/Scene/SceneBuilder/SceneDirector.h"
#include "Model/Commands/BaseCommand.h"
#include "Model/Snapshots/Caretaker.h"
class Facade
{
public:
    Facade();
    void executeCommand(BaseCommand &command);

protected:
    std::shared_ptr<BaseScene> scene;
    std::shared_ptr<Caretaker> caretaker;
};

#endif // FACADE_H
