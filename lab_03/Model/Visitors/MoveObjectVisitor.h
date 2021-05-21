//
// Created by Екатерина on 10.05.2021.
//

#ifndef LAB_03_MOVEOBJECTVISITOR_H
#define LAB_03_MOVEOBJECTVISITOR_H

#include "BaseVisitor.h"
#include "Model/Containers/matrix/matrix/matrix.h"

class MoveObjectVisitor : public BaseVisitor
{
public:
    MoveObjectVisitor(double dx, double dy, double dz);
    virtual void visitPoint(Point& point) override;
    virtual void visitEdge(Edge& edge) override;
    virtual void visitCamera(BaseCamera& camera) override;
protected:
    double dx, dy, dz;
};
#endif //LAB_03_MOVEOBJECTVISITOR_H
