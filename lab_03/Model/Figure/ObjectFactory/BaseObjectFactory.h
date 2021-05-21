#ifndef BASEOBJECTFACTORY_H
#define BASEOBJECTFACTORY_H

#include <memory>
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"
class BaseObjectFactory
{
public:
    virtual std::shared_ptr<Point> createPoint(double x, double y, double z, std::vector<double> offset) = 0;
    virtual std::shared_ptr<Edge> createEdge(std::shared_ptr<Point> start, std::shared_ptr<Point> finish, std::vector<double> offset) = 0;
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> offset) = 0;
    virtual std::shared_ptr<BaseObject> createFrameModel(std::vector<std::shared_ptr<Point>> &points,
                                                         std::vector<std::shared_ptr<Edge>> &edges) = 0;

};

#endif // BASEOBJECTFACTORY_H
