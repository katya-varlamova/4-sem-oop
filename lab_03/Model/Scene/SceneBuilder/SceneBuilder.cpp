#include "SceneBuilder.h"
SceneBuilder::SceneBuilder(double distance, std::vector<double> &worldCenterOffset)
{
    this->distance = distance;
    this->worldCenterOffset = worldCenterOffset;
}
bool SceneBuilder::buildObjects()
{
    return true;
}
bool SceneBuilder::buildCamera()
{
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory());
    camera = factory->createCamera(distance, worldCenterOffset);
    return true;
}

std::shared_ptr<BaseScene> SceneBuilder::getScene()
{
    std::shared_ptr<BaseScene> ptr(new Scene());
    ptr->setCamera(camera);
    return ptr;
}
