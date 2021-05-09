#ifndef EDGE_H
#define EDGE_H
#include "BaseEdge.h"

class Edge final : public BaseEdge
{
public:
    Edge(std::shared_ptr<BasePoint> start, std::shared_ptr<BasePoint> finish);

    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;

};

#endif // EDGE_H
