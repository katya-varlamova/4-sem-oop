#include "LoadHandler.h"

LoadHandler::LoadHandler(const char *filename, std::shared_ptr<BaseLoader> loader)
{
    this->filename = filename;
    this->loader = loader;
}
void LoadHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    loader->open(filename);
    scene = std::dynamic_pointer_cast<BaseScene>(loader->load());
    loader->close();
}
