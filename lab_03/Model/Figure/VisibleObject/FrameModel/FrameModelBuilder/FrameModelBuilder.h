#ifndef FRAMEMODELBUILDER_H
#define FRAMEMODELBUILDER_H

#include "BaseFrameModelBuilder.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
class FrameModelBuilder : public BaseFrameModelBuilder
{
public:
    FrameModelBuilder(std::vector<std::shared_ptr<Point>> points,
                      std::vector<std::shared_ptr<Edge>> edges);
    virtual bool buildEdges() override;
    virtual bool buildPoints() override;
    virtual std::shared_ptr<FrameModel> getFrameModel() override;
protected:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<Edge>> edges;
    std::vector<std::shared_ptr<Edge>> edges_copy;
    std::vector<std::shared_ptr<Point>> points_copy;
};

#endif // FRAMEMODELBUILDER_H
