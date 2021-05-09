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

    virtual bool isComposite() override;

protected:
    double distance;
    Matrix<double> transformMatrix = {{1,0,0,0},
                                                        {0,1,0,0},
                                                        {0,0,1,0},
                                                        {0,0,0,1}};
//    Matrix<double> matr;
};

#endif // BASECAMERA_H
