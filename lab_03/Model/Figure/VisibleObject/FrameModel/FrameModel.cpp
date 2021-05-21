#include "FrameModel.h"

FrameModel::FrameModel(std::vector<std::shared_ptr<Point>> points, std::vector<std::shared_ptr<Edge>> edges)
{
    this->points = points;
    this->edges = edges;
}
std::shared_ptr<BaseObject> FrameModel::clone()
{
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory());
    return factory->createFrameModel(points, edges);
}
bool FrameModel::isComposite()
{
    return false;
}
void FrameModel::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    for (auto &point : points)
        point->accept(visitor);
    for (auto &edge : edges)
        edge->accept(visitor);

}