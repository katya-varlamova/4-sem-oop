#include "LoadHandler.h"

LoadHandler::LoadHandler(std::string &name, std::shared_ptr<BaseLoader> &loader)
{
    this->name = name;
    this->loader = loader;
}
void LoadHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    loader->open(name);
    scene = std::dynamic_pointer_cast<BaseScene>(loader->load());
    loader->close();
}
