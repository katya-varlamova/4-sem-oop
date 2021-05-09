#include "Camera.h"
Camera::Camera(double distance, std::vector<double> worldPosition)
{

    this->worldPosition = worldPosition;
    this->distance = distance;
}
void Camera::accept(std::shared_ptr<BaseVisitor>& visitor)
{
    visitor->visitCamera(*this);
}
std::shared_ptr<BaseObject> Camera::clone()
{
    return std::shared_ptr<BaseObject>(new Camera(distance, worldPosition));
}
