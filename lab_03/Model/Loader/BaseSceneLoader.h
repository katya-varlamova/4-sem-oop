//
// Created by Екатерина on 18.05.2021.
//

#ifndef LAB_03_BASESCENELOADER_H
#define LAB_03_BASESCENELOADER_H

#include "BaseLoader.h"
#include "Model/Scene/Scene.h"
#include "Model/Scene/SceneBuilder/SceneBuilder.h"
#include "Model/Scene/SceneBuilder/SceneDirector.h"
class BaseSceneLoader : public BaseLoader
{
public:
    virtual std::shared_ptr<BaseObject> load() override = 0;
    virtual void open(std::string name) override = 0;
    virtual void close() override = 0;
protected:
    std::string name;
    std::shared_ptr<BaseScene> scene;
};


#endif //LAB_03_BASESCENELOADER_H
