#ifndef CAMERA_H
#define CAMERA_H

#include "Model/Figure/InvisibleObject/Camera/BaseCamera.h"
class Camera : public BaseCamera
{
public:
    Camera(direction dir, std::vector<double> offset);
    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;

};

#endif // CAMERA_H
