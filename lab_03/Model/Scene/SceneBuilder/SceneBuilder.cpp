#include "SceneBuilder.h"
SceneBuilder::SceneBuilder(std::shared_ptr<BaseCamera> camera)
{
    this->camera = camera;
}
bool SceneBuilder::buildObjects()
{
    return true;
}
bool SceneBuilder::buildCamera()
{
    return true;
}

std::shared_ptr<BaseScene> SceneBuilder::getScene()
{
    std::shared_ptr<BaseScene> ptr(new Scene());
    ptr->setCamera(camera);
    return ptr;
}
