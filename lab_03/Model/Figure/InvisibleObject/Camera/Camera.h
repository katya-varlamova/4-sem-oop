#ifndef CAMERA_H
#define CAMERA_H

#include "Model/Figure/InvisibleObject/Camera/BaseCamera.h"
class Camera : public BaseCamera
{
public:
    Camera(double distance,
           std::vector<double> &position,
           Matrix<double> transformMatrix = Matrix<double>({{1,0,0,0}, {0,1,0,0},{0,0,1,0},{0,0,0,1}}));
    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;

};

#endif // CAMERA_H
