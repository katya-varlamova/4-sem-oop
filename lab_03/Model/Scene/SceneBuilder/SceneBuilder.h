#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "Model/Scene/SceneBuilder/BaseSceneBuilder.h"
#include "Model/Scene/Scene.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
class SceneBuilder : public BaseSceneBuilder
{
public:
    SceneBuilder(double distance, std::vector<double> &worldCenterOffset);
    virtual bool buildObjects() override;
    virtual bool buildCamera() override;

    virtual std::shared_ptr<BaseScene> getScene() override;
protected:
    std::vector<std::shared_ptr<BaseObject>> objects;
    std::shared_ptr<BaseCamera> camera;
    double distance;
    std::vector<double> worldCenterOffset;
};

#endif // SCENEBUILDER_H
