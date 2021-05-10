#include "BaseEdge.h"

BaseEdge::BaseEdge(std::shared_ptr<BasePoint> &start, std::shared_ptr<BasePoint> &finish)
{
    this->start = start;
    this->finish = finish;

}
std::shared_ptr<BasePoint> BaseEdge::getStart()
{
    return start;
}
std::shared_ptr<BasePoint> BaseEdge::getFinish()
{
    return finish;
}
void BaseEdge::setStart(std::shared_ptr<BasePoint> &start)
{
    this->start = start;
}
void BaseEdge::setFinish(std::shared_ptr<BasePoint> &finish)
{
    this->finish = finish;
}
bool BaseEdge::isComposite()
{
    return false;
}
