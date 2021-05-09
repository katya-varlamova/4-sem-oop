#include "FrameModel.h"

FrameModel::FrameModel(std::vector<std::shared_ptr<BaseObject>> &objects)
{
    this->objects = objects;
}

void FrameModel::accept(std::shared_ptr<BaseVisitor>& visitor)
{
    visitor->visitFrameModel(*this);
}
std::shared_ptr<BaseObject> FrameModel::clone()
{
    std::vector<std::shared_ptr<BaseObject>> objectsCopy;
    for (auto &obj : objects)
        objectsCopy.push_back(obj->clone());
    return std::shared_ptr<BaseObject>(new FrameModel(objectsCopy));
}
