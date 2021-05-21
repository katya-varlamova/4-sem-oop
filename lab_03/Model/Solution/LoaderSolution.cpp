//
// Created by Екатерина on 21.05.2021.
//

#include "LoaderSolution.h"
std::unique_ptr<BaseLoaderCreator> LoaderSolution::create(View *view, std::string id)
{
    auto it = callbacks.find(id);
    if (it == callbacks.end()){}
    std::unique_ptr<BaseLoaderCreator> cr = (view->*(it->second))();
    return cr;
}
bool LoaderSolution::check(std::string id) {
    return callbacks.erase(id) == 1;
}
bool LoaderSolution::registration(std::string id, createCreator createCreatorFunc)
{
    return callbacks.insert(std::pair<std::string, createCreator>(id, createCreatorFunc)).second;
}