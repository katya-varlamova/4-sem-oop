//
// Created by Екатерина on 10.05.2021.
//

#include "Snapshot.h"
Snapshot::Snapshot(Scene &scene, std::shared_ptr<CompositeObject> objects, std::shared_ptr<BaseCamera> camera)
 : scene(scene)
{
    this->objects = objects;
    this->camera = camera;
}
Scene & Snapshot::getScene()
{
    scene.objects = objects;
    scene.camera = camera;
    return scene;
}