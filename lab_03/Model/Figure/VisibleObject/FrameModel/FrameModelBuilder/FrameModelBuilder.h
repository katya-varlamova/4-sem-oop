#ifndef FRAMEMODELBUILDER_H
#define FRAMEMODELBUILDER_H

#include "BaseFrameModelBuilder.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
class FrameModelBuilder : public BaseFrameModelBuilder
{
public:
    FrameModelBuilder(std::vector<std::shared_ptr<Point>> points,
                      std::vector<std::shared_ptr<Edge>> edges,
                      std::vector<double> worldOffset);
    virtual bool buildEdges() override;
    virtual bool buildPoints() override;
    virtual std::shared_ptr<FrameModel> getFrameModel() override;
protected:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<Edge>> edges;
    std::vector<double> worldOffset;
    std::shared_ptr<Primitive> primitives;
};

#endif // FRAMEMODELBUILDER_H
