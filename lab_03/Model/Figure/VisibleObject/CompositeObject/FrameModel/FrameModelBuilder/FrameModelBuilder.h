#ifndef FRAMEMODELBUILDER_H
#define FRAMEMODELBUILDER_H

#include "BaseFrameModelBuilder.h"
#include "Model/Figure/VisibleObject/Point/BasePoint.h"
#include "Model/Figure/VisibleObject/Edge/BaseEdge.h"
#include "Model/Figure/ObjectFactory/ObjectFactory.h"
class FrameModelBuilder : public BaseFrameModelBuilder
{
public:
    FrameModelBuilder(std::vector<std::shared_ptr<BasePoint>> points,
                      std::vector<std::shared_ptr<BaseEdge>> edges);
    virtual bool buildEdges() override;
    virtual bool buildPoints() override;
    virtual std::shared_ptr<FrameModel> getFrameModel() override;
protected:
    std::vector<std::shared_ptr<BasePoint>> points;
    std::vector<std::shared_ptr<BaseEdge>> edges;
    std::vector<std::shared_ptr<BaseObject>> objects;
};

#endif // FRAMEMODELBUILDER_H
