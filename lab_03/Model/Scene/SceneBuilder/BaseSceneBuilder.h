#ifndef BASESCENEBUILDER_H
#define BASESCENEBUILDER_H
#include <memory>
#include "Model/Scene/BaseScene.h"
class BaseSceneBuilder
{
public:
    virtual bool buildObjects() = 0;
    virtual bool buildCamera() = 0;
    virtual std::shared_ptr<BaseScene> getScene() = 0;
};
#endif // BASESCENEBUILDER_H
