#ifndef FRAMEMODEL_H
#define FRAMEMODEL_H

#include "Model/Figure/VisibleObject/VisibleObject.h"
#include "Model/Figure/Primitives/Primitive.h"
#include "Model/Visitors/DrawObjectVisitor.h"
#include "Model/Visitors/ProjectionVisitor.h"
class FrameModel: public VisibleObject
{
public:
    FrameModel(std::shared_ptr<Primitive> primitives, std::vector<double> worldOffset);

    virtual void accept(std::shared_ptr<BaseVisitor>& visitor) override;
    virtual std::shared_ptr<BaseObject> clone() override;
    virtual void transform(Matrix<double> &matrix) override;
    virtual bool isComposite();
    friend void DrawObjectVisitor::visit(FrameModel &model);
    friend void ProjectionVisitor::visit(FrameModel &model);
protected:
    std::shared_ptr<Primitive> primitives;
};

#endif // FRAMEMODEL_H
