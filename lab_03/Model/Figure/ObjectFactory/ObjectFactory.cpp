#include "ObjectFactory.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModelBuilder/FrameModelDirector.h"
#include "Model/Figure/VisibleObject/FrameModel/FrameModelBuilder/FrameModelBuilder.h"
std::shared_ptr<Point> ObjectFactory::createPoint(double x, double y, double z, std::vector<double> offset)
{
    return std::shared_ptr<Point>(new Point(x, y, z, offset));
}
std::shared_ptr<Edge> ObjectFactory::createEdge(std::shared_ptr<Point> start, std::shared_ptr<Point> finish, std::vector<double> offset)
{
    return std::shared_ptr<Edge>(new Edge(start, finish, offset));
}
std::shared_ptr<BaseCamera> ObjectFactory::createCamera(double distance, std::vector<double> offset)
{
    direction dir = {distance, Matrix<double>({{1, 0, 0, 0},
                                               {0, 1, 0, 0},
                                               {0, 0, 1, 0},
                                               {0, 0, 0, 1}})};
    return std::shared_ptr<BaseCamera>(new Camera(dir, offset));
}
std::shared_ptr<BaseObject> ObjectFactory::createFrameModel(std::vector<std::shared_ptr<Point>> &points,
                                                            std::vector<std::shared_ptr<Edge>> &edges)
{
    std::shared_ptr<BaseFrameModelBuilder> builder(new FrameModelBuilder(points, edges));
    std::shared_ptr<BaseFrameModelDirector> director(new FrameModelDirector());

    return director->createFrameModel(builder);
}
