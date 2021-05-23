#include "Scene.h"
#include "Model/Snapshots/Snapshot.h"
Scene::Scene()
{
    objects = std::shared_ptr<CompositeObject>(new CompositeObject());
}
std::vector<shared_ptr<BaseObject>> Scene::getObjects()
{
    return objects->getObjects();
}
Scene::Scene(std::shared_ptr<BaseScene> &scene) {
    objects = std::shared_ptr<CompositeObject>(new CompositeObject());
    for (auto& object : *scene)
    {
        objects->addObject(object->clone());
    }
    camera = std::dynamic_pointer_cast<BaseCamera>(scene->getCamera()->clone());
}
Scene::Scene(std::vector<std::shared_ptr<BaseObject>> objects, std::shared_ptr <BaseCamera> camera)
{
    this->objects = std::shared_ptr<CompositeObject>(new CompositeObject(objects));
    this->camera = camera;
}

std::vector<std::shared_ptr<BaseObject>>::const_iterator Scene::begin()
{
    return objects->begin();
}
std::vector<std::shared_ptr<BaseObject>>::const_iterator Scene::end()
{
    return objects->end();
}

std::shared_ptr <BaseCamera>& Scene::getCamera()
{
    return camera;
}
void Scene::setCamera(std::shared_ptr <BaseCamera> camera)
{
    this->camera = camera;
}

void Scene::addObject(std::shared_ptr<BaseObject> obj)
{
    objects->addObject(obj);
}
void Scene::removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter)
{
    objects->removeObject(iter);
}
std::shared_ptr<Snapshot> Scene::makeSnapshot()
{
    std::shared_ptr<CompositeObject> copy(new CompositeObject());
    for (auto &obj : *objects) {
        copy->addObject(obj->clone());
    }
    return std::shared_ptr<Snapshot>(new Snapshot(*this, copy, std::dynamic_pointer_cast<BaseCamera>(camera->clone())));
}
void Scene::restore(std::shared_ptr<Snapshot> shot)
{
    *this = shot->getScene();
}
std::shared_ptr<BaseObject> Scene::clone()
{
    std::shared_ptr<CompositeObject>copyObjects;
    for (auto &obj : *objects)
        copyObjects->addObject(obj->clone());
    std::shared_ptr<BaseCamera> copyCamera = std::dynamic_pointer_cast<BaseCamera>(camera->clone());
    return std::shared_ptr<BaseObject> (new Scene(copyObjects->getObjects(), copyCamera));
}