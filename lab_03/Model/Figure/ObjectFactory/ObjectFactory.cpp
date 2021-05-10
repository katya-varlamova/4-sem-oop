#include "ObjectFactory.h"
std::shared_ptr<BasePoint> ObjectFactory::createPoint(double x, double y, double z)
{
    return std::shared_ptr<BasePoint>(new Point(x, y, z));
}
std::shared_ptr<BaseEdge> ObjectFactory::createEdge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish)
{
    return std::shared_ptr<BaseEdge>(new Edge(start, finish));
}
std::shared_ptr<BaseCamera> ObjectFactory::createCamera(double distance, std::vector<double> &position)
{
    return std::shared_ptr<BaseCamera>(new Camera(distance, position));
}
std::shared_ptr<BaseObject> ObjectFactory::createFrameModel(std::vector<std::shared_ptr<BasePoint>> &points,
                                                            std::vector<std::shared_ptr<BaseEdge>> &edges)
{
    std::shared_ptr<BaseFrameModelBuilder> builder(new FrameModelBuilder(points, edges));
    std::shared_ptr<BaseFrameModelDirector> director(new FrameModelDirector());

    return director->createFrameModel(builder);
}
