#include "CompositeObject.h"
CompositeObject::CompositeObject(std::vector<std::shared_ptr<BaseObject>> &objects)
{
    objects = objects;
}
bool CompositeObject::isComposite()
{
    return true;
}
void CompositeObject::addObject(std::shared_ptr<BaseObject> obj)
{
    objects.push_back(obj);
}
void CompositeObject::removeObject(std::vector<std::shared_ptr<BaseObject>>::const_iterator iter)
{
    objects.erase(iter);
}

std::vector<std::shared_ptr<BaseObject>>::const_iterator CompositeObject::begin()
{
    return objects.begin();
}
std::vector<std::shared_ptr<BaseObject>>::const_iterator CompositeObject::end()
{
    return objects.end();
}
void CompositeObject::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    visitor->visit(*this);
}
bool CompositeObject::isInvisible()
{
    return false;
}
std::shared_ptr<BaseObject> CompositeObject::clone()
{
    std::vector<std::shared_ptr<BaseObject>> objectsCopy;
    for (auto &obj : objects)
        objectsCopy.push_back(obj->clone());
    return std::shared_ptr<BaseObject> (new CompositeObject(objectsCopy));
}
void CompositeObject::transform(Matrix<double> &transformMatrix)
{
    for (auto &obj : objects)
        obj->transform(transformMatrix);
}
std::vector<std::shared_ptr<BaseObject>> CompositeObject::getObjects()
{
    return objects;
}