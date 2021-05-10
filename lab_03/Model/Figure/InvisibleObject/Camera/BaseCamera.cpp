#include "BaseCamera.h"
void BaseCamera::setTransformMatrix(Matrix<double> &transformMatrix)
{
    this->transformMatrix = transformMatrix;
}
Matrix<double> BaseCamera::getTransformMatrix()
{
    return Matrix<double>(transformMatrix);
}

void BaseCamera::setDistance(double distance)
{
    this->distance = distance;
}
double BaseCamera::getDistance()
{
    return distance;
}
void BaseCamera::setPosition(std::vector<double> position)
{
    this->position = position;
}
std::vector<double> BaseCamera::getPosition()
{
    return position;
}
bool BaseCamera::isComposite()
{
    return true;
}
