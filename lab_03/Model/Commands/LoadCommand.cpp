//
// Created by Екатерина on 16.05.2021.
//

#include "LoadCommand.h"
LoadCommand::LoadCommand(std::shared_ptr<BaseLoader> loader, std::string name)
{
    this->name = name;
    this->loader = loader;
}
void LoadCommand::execute(std::shared_ptr<BaseScene> &scene, std::shared_ptr<Caretaker> &caretaker)
{
    LoadHandler lh(name, loader);
    lh.handle(scene);
}