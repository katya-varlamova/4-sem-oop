#include "FrameModelBuilder.h"

FrameModelBuilder::FrameModelBuilder(std::vector<std::shared_ptr<BasePoint>> points, std::vector<std::shared_ptr<BaseEdge>> edges)
{
    this->points = points;
    this->edges = edges;
}
bool FrameModelBuilder::buildEdges()
{
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory());
    for (auto edge : edges)
    {
        objects.push_back(factory->createEdge(edge->getStart(),
                                             edge->getFinish()));
    }
    return true;
}
bool FrameModelBuilder::buildPoints()
{
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory());
    for (auto point : points)
    {
        objects.push_back(factory->createPoint(point->getX(),
                                              point->getY(),
                                              point->getZ()));
    }
    return true;
}
std::shared_ptr<FrameModel> FrameModelBuilder::getFrameModel()
{
    return std::shared_ptr<FrameModel> (new FrameModel(objects));
}
