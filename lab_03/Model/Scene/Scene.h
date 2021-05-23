#ifndef SCENE_H
#define SCENE_H

#include "Model/Scene/BaseScene.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
#include <vector>
class Scene : public BaseScene
{
public:
    friend Snapshot;
    Scene();
    Scene(std::vector<std::shared_ptr<BaseObject>> objects, std::shared_ptr <BaseCamera> camera);
    Scene(std::shared_ptr<BaseScene> &scene);
    virtual std::vector<std::shared_ptr<BaseObject>>::const_iterator begin() override;
    virtual std::vector<std::shared_ptr<BaseObject>>::const_iterator end() override;

    virtual std::shared_ptr <BaseCamera>& getCamera() override;
    virtual void setCamera(std::shared_ptr <BaseCamera> camera) override;

    virtual void addObject(std::shared_ptr<BaseObject> obj) override;
    virtual void removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter) override;

    virtual std::vector<shared_ptr<BaseObject>> getObjects() override;

    virtual std::shared_ptr<Snapshot> makeSnapshot() override;
    virtual void restore(std::shared_ptr<Snapshot>) override;

    virtual std::shared_ptr<BaseObject> clone() override;

};

#endif // SCENE_H
