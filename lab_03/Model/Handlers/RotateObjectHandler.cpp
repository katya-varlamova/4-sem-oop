#include "RotateObjectHandler.h"

RotateObjectHandler::RotateObjectHandler(double ax, double ay, double az)
{
    this->ax = ax;
    this->ay = ay;
    this->az = az;
}
void RotateObjectHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    Matrix<double> rotationX = {{1, 0, 0, 0},
                                {0, cos(ax), -sin(ax), 0},
                                {0, sin(ax), cos(ax), 0},
                                {0, 0, 0,  1}};

    Matrix<double> rotationY = {{cos(ay), 0, -sin(ay), 0},
                                {0, 1, 0, 0},
                                {sin(ay), 0, cos(ay), 0},
                                {0, 0, 0,  1}};

    Matrix<double> rotationZ = {{cos(az), -sin(az), 0, 0},
                                {sin(az), cos(az), 0, 0},
                                {0, 0, 1, 0},
                                {0, 0, 0,  1}};
    Matrix<double>rotationMatrix = rotationX * rotationY;
    rotationMatrix *= rotationZ;
    std::shared_ptr<BaseVisitor> visitor( new TransformObjectVisitor(rotationMatrix));
    for (auto &obj : *scene)
        obj->accept(visitor);
}