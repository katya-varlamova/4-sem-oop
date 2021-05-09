#ifndef BASEVISITOR_H
#define BASEVISITOR_H

class BaseCamera;
class BasePoint;
class BaseEdge;
class FrameModel;

class BaseVisitor
{
public:
    BaseVisitor();
    virtual void visitPoint(BasePoint& point) = 0;
    virtual void visitEdge(BaseEdge& edge) = 0;
    virtual void visitFrameModel(FrameModel &model) = 0;
    virtual void visitCamera(BaseCamera& camera) = 0;
};

#endif // BASEVISITOR_H
