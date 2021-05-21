//
// Created by Екатерина on 21.05.2021.
//

#include "GraphicsSolution.h"
#include "vector"
std::unique_ptr<BaseDrawerCreator> GraphicsSolution::create(View *view, std::string id)
{
    auto it = callbacks.find(id);
    if (it == callbacks.end()){}
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