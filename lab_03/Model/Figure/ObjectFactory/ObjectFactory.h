#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "BaseObjectFactory.h"
class ObjectFactory final: public BaseObjectFactory
{
public:
    virtual std::shared_ptr<BasePoint> createPoint(double x, double y, double z) override;
    virtual std::shared_ptr<BaseEdge> createEdge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish) override;
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> worldPosition) override;
};

#endif // OBJECTFACTORY_H
