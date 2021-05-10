#ifndef BASEFRAMEMODELDIRECTOR_H
#define BASEFRAMEMODELDIRECTOR_H
#include "Model/Figure/VisibleObject/CompositeObject/FrameModel/FrameModel.h"
#include "BaseFrameModelBuilder.h"
#include <memory>
class BaseFrameModelDirector
{
public:
    virtual std::shared_ptr<FrameModel> createFrameModel(std::shared_ptr<BaseFrameModelBuilder> builder) = 0;

};

#endif // BASEFRAMEMODELDIRECTOR_H
