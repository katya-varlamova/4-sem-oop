#ifndef FRAMEMODELDIRECTOR_H
#define FRAMEMODELDIRECTOR_H
#include "BaseFrameModelDirector.h"
class FrameModelDirector : public BaseFrameModelDirector
{
public:
    virtual std::shared_ptr<FrameModel> createFrameModel(std::shared_ptr<BaseFrameModelBuilder> builder) override;

};

#endif // FRAMEMODELDIRECTOR_H
