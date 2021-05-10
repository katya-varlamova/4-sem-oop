#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "Model/Figure/InvisibleObject/InvisibleObject.h"
#include "vector"
#include "Model/Containers/matrix/matrix/matrix.h"
class BaseCamera : public InvisibleObject
{
public:
    void setTransformMatrix(Matrix<double> &transformMatrix);
    Matrix<double> getTransformMatrix();

    void setDistance(double distance);
    double getDistance();

    std::vector<double> getPosition();
    void setPosition(std::vector<double> );

    virtual bool isComposite() override;

protected:
    double distance;
    Matrix<double> transformMatrix;
    std::vector<double> position;
};

#endif // BASECAMERA_H
