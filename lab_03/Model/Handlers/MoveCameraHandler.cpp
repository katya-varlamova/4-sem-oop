#include "MoveCameraHandler.h"
MoveCameraHandler::MoveCameraHandler(double dx, double dy, double dz)
{

}
void MoveCameraHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    Matrix<double> transMatr = {{1, 0, 0, -dx},
                                {0, 1, 0, -dy},
                                {0, 0, 1, -dz},
                                {0, 0, 0,  1}};
    std::shared_ptr<BaseVisitor> visitor( new TransformObjectVisitor(transMatr));
    scene->getCamera()->accept(visitor);
}