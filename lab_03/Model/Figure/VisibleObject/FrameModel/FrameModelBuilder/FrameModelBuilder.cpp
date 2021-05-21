#include "FrameModelBuilder.h"

FrameModelBuilder::FrameModelBuilder(std::vector<std::shared_ptr<Point>> points, std::vector<std::shared_ptr<Edge>> edges)
{
    this->points = points;
    this->edges = edges;
}
bool FrameModelBuilder::buildEdges()
{
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory());
    for (auto edge : edges)
    {
        edges_copy.push_back(factory->createEdge(edge->getStart()->clone(),
                                             edge->getFinish()->clone(),
                                             edge->getOffset()));
    }
    return true;
}
bool FrameModelBuilder::buildPoints()
{
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory());
    for (auto point : points)
    {
        points_copy.push_back(factory->createPoint(point->getX(),
                                              point->getY(),
                                              point->getZ(),
                                              point->getOffset()));
    }
    return true;
}
std::shared_ptr<FrameModel> FrameModelBuilder::getFrameModel()
{
    return std::shared_ptr<FrameModel> (new FrameModel(points_copy, edges_copy));
}
