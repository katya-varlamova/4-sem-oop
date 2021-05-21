#include "CompositeObject.h"

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
