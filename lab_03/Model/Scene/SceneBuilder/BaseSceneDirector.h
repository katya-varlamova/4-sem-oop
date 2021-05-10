#ifndef BASESCENEDIRECTOR_H
#define BASESCENEDIRECTOR_H
#include "Model/Scene/BaseScene.h"
#include "BaseSceneBuilder.h"
class BaseSceneDirector
{
public:
    virtual std::shared_ptr<BaseScene> createScene(std::shared_ptr<BaseSceneBuilder> &builder) = 0;
};
#endif // BASESCENEDIRECTOR_H
