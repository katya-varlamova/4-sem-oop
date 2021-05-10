#ifndef BASEFRAMEMODELBUILDER_H
#define BASEFRAMEMODELBUILDER_H

#include <memory>
#include <vector>
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.h"
class BaseFrameModelBuilder
{
public:
    virtual bool buildPoints() = 0;
    virtual bool buildEdges() = 0;
    virtual std::shared_ptr<FrameModel> getFrameModel() = 0;
};

#endif // BASEFRAMEMODELBUILDER_H
