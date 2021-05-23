#include "Edge.h"

Edge::Edge(size_t start, size_t finish)
{
    this->start = start;
    this->finish = finish;
}
Edge::Edge(Edge &edge)
{
    this->start = edge.start;
    this->finish = edge.finish;
}
size_t Edge::getStart()
{
    return start;
}
size_t Edge::getFinish()
{
    return finish;
}
void Edge::setStart(size_t start)
{
    this->start = start;
}
void Edge::setFinish(size_t finish)
{
    this->finish = finish;
}

std::shared_ptr<Edge> Edge::clone()
{
    return std::shared_ptr<Edge>(new Edge(start, finish));
}