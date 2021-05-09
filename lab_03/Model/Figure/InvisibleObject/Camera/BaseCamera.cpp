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
bool BaseCamera::isComposite()
{
    return true;
}
