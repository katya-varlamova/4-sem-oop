#include "ObjectFactory.h"

std::shared_ptr<BaseCamera> ObjectFactory::createCamera(double distance, std::vector<double> offset)
{
    direction dir = {distance, Matrix<double>({{1, 0, 0, 0},
                                               {0, 1, 0, 0},
                                               {0, 0, 1, 0},
                                               {0, 0, 0, 1}})};
    return std::shared_ptr<BaseCamera>(new Camera(dir, offset));
}
//std::shared_ptr<BaseObject> ObjectFactory::createFrameModel(std::vector<std::shared_ptr<Point>> &points,
//                                                            std::vector<std::shared_ptr<Edge>> &edges)
//{
//    std::shared_ptr<BaseFrameModelBuilder> builder(new FrameModelBuilder(points, edges));
//    std::shared_ptr<BaseFrameModelDirector> director(new FrameModelDirector());
//
//    return director->createFrameModel(builder);
//}
