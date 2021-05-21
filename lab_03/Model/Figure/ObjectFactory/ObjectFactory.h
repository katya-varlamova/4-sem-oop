#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include <vector>
#include "BaseObjectFactory.h"

class ObjectFactory final: public BaseObjectFactory
{
public:
    virtual std::shared_ptr<Point> createPoint(double x, double y, double z, std::vector<double> offset) override;
    virtual std::shared_ptr<Edge> createEdge(std::shared_ptr<Point> start, std::shared_ptr<Point> finish, std::vector<double> offset) override;
    virtual std::shared_ptr<BaseCamera> createCamera(double distance, std::vector<double> offset) override;
    virtual std::shared_ptr<BaseObject> createFrameModel(std::vector<std::shared_ptr<Point>> &points,
                                                 std::vector<std::shared_ptr<Edge>> &edges) override;
};

#endif // OBJECTFACTORY_H
