#ifndef BASEVISITOR_H
#define BASEVISITOR_H
#include <memory>
class BaseCamera;
class FrameModel;
class CompositeObject;
class BaseVisitor
{
public:
    BaseVisitor() = default;
    virtual void visit(BaseCamera &camera) = 0;
    virtual void visit(FrameModel &model) = 0;
    virtual void visit(CompositeObject &compositeObject) = 0;
};

#endif // BASEVISITOR_H
