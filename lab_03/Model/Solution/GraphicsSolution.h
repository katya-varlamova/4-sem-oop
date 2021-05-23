//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_GRAPHICSSOLUTION_H
#define LAB_03_GRAPHICSSOLUTION_H

#include <string>
#include <map>
#include "Drawer/DrawerFactory/BaseDrawerCreator.h"
#include "Model/Errors/Exception.h"
class View;
class GraphicsSolution {
    typedef std::unique_ptr<BaseDrawerCreator> (View::*createCreator)(void);
public:
    bool registration(std::string id, createCreator createCreatorFunc);
    bool check(std::string id);
    std::unique_ptr<BaseDrawerCreator> create(View *view, std::string id);

private:
    std::map<std::string, createCreator> callbacks;
};


#endif //LAB_03_GRAPHICSSOLUTION_H
