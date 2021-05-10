#include "FrameModelDirector.h"

std::shared_ptr<FrameModel> FrameModelDirector::createFrameModel(std::shared_ptr<BaseFrameModelBuilder> builder)
{
    if (builder->buildEdges() && builder->buildPoints())
        return builder->getFrameModel();
    return std::shared_ptr<FrameModel>();
}
