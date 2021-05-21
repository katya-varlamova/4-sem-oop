#ifndef Edge_H
#define Edge_H
#include <memory>
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/VisibleObject/VisibleObject.h"
class Edge
{
public:
    Edge(std::shared_ptr<Point> start, std::shared_ptr<Point> finish, std::vector<double> offset = {0, 0, 0});
    Edge(Edge &edge);

    std::shared_ptr<Point> getStart();
    std::shared_ptr<Point> getFinish();

    void setStart(std::shared_ptr<Point> &start);
    void setFinish(std::shared_ptr<Point> &finish);

    void accept(std::shared_ptr<BaseVisitor>& visitor);
    std::shared_ptr<Edge> clone();

    std::vector<double>  getOffset();
    void setOffset(std::vector<double> offset);
protected:
    std::shared_ptr<Point> start, finish;
    std::vector<double> worldOffset;
};

#endif // Edge_H
