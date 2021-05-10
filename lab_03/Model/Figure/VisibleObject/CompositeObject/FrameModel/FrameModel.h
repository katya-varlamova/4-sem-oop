#ifndef FRAMEMODEL_H
#define FRAMEMODEL_H

#include "Model/Figure/VisibleObject/CompositeObject/CompositeObject.h"

class FrameModel final: public CompositeObject
{
public:
    FrameModel(std::vector<std::shared_ptr<BaseObject>> &objects);

    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;
};

#endif // FRAMEMODEL_H
