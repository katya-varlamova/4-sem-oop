#include "SceneDirector.h"

std::shared_ptr<BaseScene> SceneDirector::createScene(std::shared_ptr<BaseSceneBuilder> &builder)
{
    if (builder->buildObjects() && builder->buildCamera())
        return builder->getScene();
     return std::shared_ptr<BaseScene>();

}
