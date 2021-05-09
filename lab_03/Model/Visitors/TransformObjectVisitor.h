#ifndef TRANSFORMOBJECTVISITOR_H
#define TRANSFORMOBJECTVISITOR_H

#include "BaseVisitor.h"
#include "Model/Containers/matrix/matrix/matrix.h"

class TransformObjectVisitor : public BaseVisitor
{
public:
    TransformObjectVisitor(Matrix<double> &transformMatrix);
    virtual void visitPoint(BasePoint& point) override;
    virtual void visitEdge(BaseEdge& edge) override;
    virtual void visitFrameModel(FrameModel &model) override;
    virtual void visitCamera(BaseCamera& camera) override;
protected:
    Matrix<double> transformMatrix = {{1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}};
};

#endif // TRANSFORMOBJECTVISITOR_H
