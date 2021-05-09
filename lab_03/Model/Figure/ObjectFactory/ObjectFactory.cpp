#include "ObjectFactory.h"
std::shared_ptr<BasePoint> ObjectFactory::createPoint(double x, double y, double z)
{
    return std::shared_ptr<BasePoint>(new Point(x, y, z));
}
std::shared_ptr<BaseEdge> ObjectFactory::createEdge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish)
{
    return std::shared_ptr<BaseEdge>(new Edge(start, finish));
}
std::shared_ptr<BaseCamera> ObjectFactory::createCamera(double distance, std::vector<double> worldPosition)
{
    return std::shared_ptr<BaseCamera>(new Camera(distance, worldPosition));
}
