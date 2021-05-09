#include "Edge.h"

Edge::Edge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish) : BaseEdge(start, finish) {};

void Edge::accept(std::shared_ptr<BaseVisitor> &visitor)
{
    visitor->visitEdge(*this);
}

std::shared_ptr<BaseObject> Edge::clone()
{
    return std::shared_ptr<BaseObject>(new Edge(std::dynamic_pointer_cast<BasePoint>(start->clone()),
                                                std::dynamic_pointer_cast<BasePoint>(finish->clone())));
}
