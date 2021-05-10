#include "Camera.h"
Camera::Camera(double distance, std::vector<double> &position, Matrix<double> transformMatrix)
{
    this->position = position;
    this->distance = distance;
    this->transformMatrix = transformMatrix;
}
void Camera::accept(std::shared_ptr<BaseVisitor>& visitor)
{
    visitor->visitCamera(*this);
}
std::shared_ptr<BaseObject> Camera::clone()
{
    return std::shared_ptr<BaseObject>(new Camera(distance, position, Matrix<double>(transformMatrix)));
}
