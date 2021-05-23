#include "Camera.h"
Camera::Camera(direction dir, std::vector<double> offset)
{
    this->dir = dir;
    this->worldOffset = offset;
}
void Camera::accept(std::shared_ptr<BaseVisitor>& visitor)
{
    visitor->visit(*this);
}
std::shared_ptr<BaseObject> Camera::clone()
{
    return std::shared_ptr<BaseObject>(new Camera(dir, worldOffset));
}
void Camera::transform(Matrix<double> &transformMatrix)
{
    this->dir.transformMatrix *= transformMatrix;
}