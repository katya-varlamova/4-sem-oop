//
// Created by Екатерина on 09.05.2021.
//

#ifndef LAB_03_PROJECTIONVISITOR_H
#define LAB_03_PROJECTIONVISITOR_H

#include "BaseVisitor.h"
#include <memory>
#include <vector>
#include "Model/Containers/matrix/matrix/matrix.h"
class ProjectionVisitor : public BaseVisitor
{
public:
    ProjectionVisitor(std::shared_ptr<BaseCamera> &camera);
    void visitPoint(Point &point) override;
    void visitEdge(Edge &edge) override;
    void visitCamera(BaseCamera &camera) override;

protected:
    std::shared_ptr<BaseCamera> camera;
};


#endif //LAB_03_PROJECTIONVISITOR_H
