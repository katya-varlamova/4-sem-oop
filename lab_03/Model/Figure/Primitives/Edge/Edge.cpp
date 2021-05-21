#include "Edge.h"

Edge::Edge(std::shared_ptr<Point> start, std::shared_ptr<Point> finish, std::vector<double> offset)
{
    this->start = start;
    this->finish = finish;
    this->worldOffset = offset;
}
Edge::Edge(Edge &edge)
{
    this->start = edge.start;
    this->finish = edge.finish;
    this->worldOffset = edge.worldOffset;
}
std::shared_ptr<Point> Edge::getStart()
{
    return start;
}
std::shared_ptr<Point> Edge::getFinish()
{
    return finish;
}
void Edge::setStart(std::shared_ptr<Point> &start)
{
    this->start = start;
}
void Edge::setFinish(std::shared_ptr<Point> &finish)
{
    this->finish = finish;
}
void Edge::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    visitor->visitEdge(*this);
}

std::shared_ptr<Edge> Edge::clone()
{
    return std::shared_ptr<Edge>(new Edge(start->clone(), finish->clone(), worldOffset));
}
std::vector<double> Edge::getOffset()
{
    return worldOffset;
}

void Edge::setOffset(std::vector<double> offset)
{
    this->worldOffset = offset;
}
