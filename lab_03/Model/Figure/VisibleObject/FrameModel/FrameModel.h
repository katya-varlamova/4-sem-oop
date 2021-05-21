#ifndef FRAMEMODEL_H
#define FRAMEMODEL_H

#include "Model/Figure/VisibleObject/VisibleObject.h"
#include "Model/Figure/Primitives/Point/Point.h"
#include "Model/Figure/Primitives/Edge/Edge.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
class FrameModel: public VisibleObject
{
public:
    FrameModel(std::vector<std::shared_ptr<Point>> points, std::vector<std::shared_ptr<Edge>> edges);

    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;
    virtual bool isComposite();

protected:
    std::vector<std::shared_ptr<Edge>> edges;
    std::vector<std::shared_ptr<Point>> points;
};

#endif // FRAMEMODEL_H
