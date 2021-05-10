#include "Scene.h"
#include "Model/Snapshots/Snapshot.h"
Scene::Scene(std::shared_ptr<BaseScene> &scene) {
    for (auto& object : *scene)
    {
        objects.push_back(object->clone());
    }
    camera = std::dynamic_pointer_cast<BaseCamera>(scene->getCamera()->clone());
}
Scene::Scene(std::vector<std::shared_ptr<BaseObject>> objects, std::shared_ptr <BaseCamera> camera)
{
    this->objects = objects;
    this->camera = camera;
}

std::vector<std::shared_ptr<BaseObject>>::const_iterator Scene::begin()
{
    return objects.begin();
}
std::vector<std::shared_ptr<BaseObject>>::const_iterator Scene::end()
{
    return objects.end();
}

std::shared_ptr <BaseCamera>& Scene::getCamera()
{
    return camera;
}
void Scene::setCamera(std::shared_ptr <BaseCamera> &camera)
{
    this->camera = camera;
}

void Scene::addObject(std::shared_ptr<BaseObject> &obj)
{
    objects.push_back(obj);
}
void Scene::removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter)
{
    objects.erase(iter);
}

std::shared_ptr<BaseObject> Scene::getObject(size_t i)
{
    return objects[i];
}
void Scene::setObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter, std::shared_ptr<BaseObject> &obj)
{
    objects.insert(iter, obj);
}
std::shared_ptr<Snapshot> Scene::makeSnapshot()
{
    std::vector<std::shared_ptr<BaseObject>> copy;
    for (auto &obj : objects)
        copy.push_back(obj->clone());
    return std::shared_ptr<Snapshot>(new Snapshot(*this, copy, std::dynamic_pointer_cast<BaseCamera>(camera->clone())));
}
void Scene::restore(std::shared_ptr<Snapshot> shot)
{
    *this = shot->getScene();
}
std::shared_ptr<BaseScene> Scene::clone()
{
    std::vector<std::shared_ptr<BaseObject>> copyObjects;
    for (auto &obj : objects)
        copyObjects.push_back(obj->clone());
    std::shared_ptr<BaseCamera> copyCamera = std::dynamic_pointer_cast<BaseCamera>(camera->clone());
    return std::shared_ptr<BaseScene> (new Scene(copyObjects, copyCamera));
}