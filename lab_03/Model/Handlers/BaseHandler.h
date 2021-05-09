#ifndef BASEHANDLER_H
#define BASEHANDLER_H

#include "Model/Scene/Scene.h"
class BaseHandler
{
public:
    virtual void handle(std::shared_ptr<BaseScene> &scene) = 0;
};

#endif // BASEHANDLER_H
