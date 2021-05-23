#include "FrameModelDirector.h"

std::shared_ptr<FrameModel> FrameModelDirector::createFrameModel(std::shared_ptr<BaseFrameModelBuilder> builder)
{
    if (builder->buildPoints() && builder->buildEdges())
        return builder->getFrameModel();
    return std::shared_ptr<FrameModel>();
}
