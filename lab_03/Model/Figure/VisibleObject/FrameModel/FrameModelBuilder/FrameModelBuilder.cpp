#include "FrameModelBuilder.h"

FrameModelBuilder::FrameModelBuilder(std::vector<std::shared_ptr<Point>> points, std::vector<std::shared_ptr<Edge>> edges,
                                     std::vector<double> worldOffset)
{
    this->points = points;
    this->edges = edges;
    this->worldOffset = worldOffset;
    primitives = std::shared_ptr<Primitive>(new Primitive);
}
bool FrameModelBuilder::buildEdges()
{
    for (auto &edge : edges)
    {
        primitives->addEdge(std::shared_ptr<Edge>(new Edge(edge->getStart(),
                                             edge->getFinish())));
    }
    return true;
}
bool FrameModelBuilder::buildPoints()
{
    for (auto &point : points)
    {
        primitives->addPoint(std::shared_ptr<Point>(new Point(point->getX(),
                                              point->getY(),
                                              point->getZ())));
    }
    return true;
}
std::shared_ptr<FrameModel> FrameModelBuilder::getFrameModel()
{
    return std::shared_ptr<FrameModel> (new FrameModel(primitives, worldOffset));
}
