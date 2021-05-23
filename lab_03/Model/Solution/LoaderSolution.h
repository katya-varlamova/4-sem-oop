//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_LOADERSOLUTION_H
#define LAB_03_LOADERSOLUTION_H

#include <string>
#include <map>
#include "Model/Loader/BaseLoader.h"
#include "Model/Loader/LoaderCreator/BaseLoaderCreator.h"
#include "Model/Errors/Exception.h"
class View;
class LoaderSolution {
    typedef std::unique_ptr<BaseLoaderCreator> (View::*createCreator)();
public:
    bool registration(std::string id, createCreator createCreatorFunc);
    bool check(std::string id);
    std::unique_ptr<BaseLoaderCreator> create(View *view, std::string id);

private:
    std::map<std::string, createCreator> callbacks;
};


#endif //LAB_03_LOADERSOLUTION_H
