#ifndef BASEOBJECTFACTORY_H
#define BASEOBJECTFACTORY_H

#include <memory>
#include "Model/Figure/VisibleObject/Point/Point.h"
#include "Model/Figure/VisibleObject/Edge/Edge.h"
#include "Model/Figure/InvisibleObject/Camera/Camera.h"

class BaseObjectFactory
{
public:
    virtual std::shared_ptr<BasePoint> createPoint(double x, double y, double z) = 0;
    virtual std::shared_ptr<BaseEdge> createEdge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish) = 0;
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> &position) = 0;
    virtual std::shared_ptr<BaseObject> createFrameModel(std::vector<std::shared_ptr<BasePoint>> &points,
                                                         std::vector<std::shared_ptr<BaseEdge>> &edges) = 0;

};

#endif // BASEOBJECTFACTORY_H
