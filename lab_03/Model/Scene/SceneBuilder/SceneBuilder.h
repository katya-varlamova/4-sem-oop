#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "Model/Scene/SceneBuilder/BaseSceneBuilder.h"
#include "Model/Scene/Scene.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder(std::shared_ptr<BaseCamera> camera);
    virtual bool buildObjects() override;
    virtual bool buildCamera() override;

    virtual std::shared_ptr<BaseScene> getScene() override;
protected:
    std::shared_ptr<BaseCamera> camera;
};

#endif // SCENEBUILDER_H
