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
    virtual void visit(BaseCamera &camera) override;
    virtual void visit(FrameModel &model) override;
    virtual void visit(CompositeObject &compositeObject) override;

protected:
    std::shared_ptr<BaseCamera> camera;
};


#endif //LAB_03_PROJECTIONVISITOR_H
