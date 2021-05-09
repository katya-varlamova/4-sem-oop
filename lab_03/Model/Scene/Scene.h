#ifndef SCENE_H
#define SCENE_H

#include "Model/Scene/BaseScene.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include <vector>
class Scene : public BaseScene
{
public:
    Scene() = default;
    Scene(std::shared_ptr<BaseScene> &scene);
    virtual std::vector<std::shared_ptr<BaseObject>>::const_iterator begin() override;
    virtual std::vector<std::shared_ptr<BaseObject>>::const_iterator end() override;

    virtual std::shared_ptr <BaseCamera>& getCamera() override;
    virtual void setCamera(std::shared_ptr <BaseCamera> &camera) override;

    virtual void addObject(std::shared_ptr<BaseObject> &obj) override;
    virtual void removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter) override;

    virtual std::shared_ptr<BaseObject> getObject(size_t i) override;
    virtual void setObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter, std::shared_ptr<BaseObject> &obj) override;
};

#endif // SCENE_H