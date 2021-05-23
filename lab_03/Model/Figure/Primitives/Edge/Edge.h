#ifndef Edge_H
#define Edge_H
#include <memory>
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/VisibleObject/VisibleObject.h"
class Edge
{
public:
    Edge(size_t start, size_t finish);
    Edge(Edge &edge);

    size_t getStart();
    size_t getFinish();

    void setStart(size_t start);
    void setFinish(size_t finish);

    std::shared_ptr<Edge> clone();
protected:
    size_t start, finish;
};

#endif // Edge_H
