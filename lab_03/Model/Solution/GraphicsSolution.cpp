//
// Created by Екатерина on 21.05.2021.
//

#include "GraphicsSolution.h"
#include "vector"
std::unique_ptr<BaseDrawerCreator> GraphicsSolution::create(View *view, std::string id)
{
    auto it = callbacks.find(id);
    if (it == callbacks.end())
    {
        throw IdException(__FILE__, __LINE__, __TIME__, "there is no registered creator with such id");
    }
    std::unique_ptr<BaseDrawerCreator> cr = (view->*(it->second))();
    return cr;
}
bool GraphicsSolution::check(std::string id) {
    return callbacks.erase(id) == 1;
}
bool GraphicsSolution::registration(std::string id, createCreator createCreatorFunc)
{
    return callbacks.insert(std::pair<std::string, createCreator>(id, createCreatorFunc)).second;
}