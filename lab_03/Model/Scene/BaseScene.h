#ifndef BASESCENE_H
#define BASESCENE_H
#include "Model/Figure/BaseObject.h"
#include <memory>
#include <vector>
#include "Model/Figure/InvisibleObject/Camera/BaseCamera.h"
class BaseScene
{
public:

    virtual std::vector<std::shared_ptr<BaseObject>>::const_iterator begin() = 0;
    virtual std::vector<std::shared_ptr<BaseObject>>::const_iterator end() = 0;

    virtual std::shared_ptr <BaseCamera>& getCamera() = 0;
    virtual void setCamera(std::shared_ptr <BaseCamera> &camera) = 0;

    virtual void addObject(std::shared_ptr<BaseObject> &obj) = 0;
    virtual void removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter) = 0;

    virtual std::shared_ptr<BaseObject> getObject(size_t i) = 0;
    virtual void setObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter, std::shared_ptr<BaseObject> &obj) = 0;

protected:
    std::vector<std::shared_ptr<BaseObject>> objects;
    std::shared_ptr <BaseCamera> camera;

};

#endif // BASESCENE_H
