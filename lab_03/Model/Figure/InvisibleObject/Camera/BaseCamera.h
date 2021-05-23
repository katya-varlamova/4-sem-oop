#ifndef BASECAMERA_H
#define BASECAMERA_H

#include "Model/Figure/InvisibleObject/InvisibleObject.h"
#include "vector"
#include "Model/Containers/matrix/matrix/matrix.h"
typedef struct
{
    double distance;
    Matrix<double> transformMatrix;
} direction;
class BaseCamera : public InvisibleObject
{
public:
    virtual bool isComposite() override;
    direction getDirection();
protected:
    direction dir;
};

#endif // BASECAMERA_H
