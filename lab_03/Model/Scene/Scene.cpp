#include "Scene.h"
Scene::Scene(std::shared_ptr<BaseScene> &scene) {
    for (auto& object : *scene)
    {
        objects.push_back(object->clone());
    }
    camera = std::dynamic_pointer_cast<BaseCamera>(scene->getCamera()->clone());
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
