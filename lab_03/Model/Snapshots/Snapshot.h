//
// Created by Екатерина on 10.05.2021.
//

#ifndef LAB_03_SNAPSHOT_H
#define LAB_03_SNAPSHOT_H
#include <memory>
#include "Model/Scene/Scene.h"
class Snapshot
{
public:
    Snapshot(Scene &scene, std::shared_ptr<CompositeObject> objects, std::shared_ptr<BaseCamera> camera);
    Scene & getScene();
protected:
    Scene &scene;
    std::shared_ptr<CompositeObject> objects;
    std::shared_ptr<BaseCamera> camera;
};


#endif //LAB_03_SNAPSHOT_H
