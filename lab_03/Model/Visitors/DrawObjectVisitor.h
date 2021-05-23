//
// Created by Екатерина on 09.05.2021.
//

#ifndef LAB_03_DRAWOBJECTVISITOR_H
#define LAB_03_DRAWOBJECTVISITOR_H
#include "BaseVisitor.h"
#include "Drawer/BaseDrawer.h"
#include "Model/Figure/CompositeObject/CompositeObject.h"
class DrawObjectVisitor : public BaseVisitor
{
public:
    DrawObjectVisitor(std::shared_ptr<BaseDrawer>& drawer);
    virtual void visit(BaseCamera &camera) override;
    virtual void visit(FrameModel &model) override;
    virtual void visit(CompositeObject &compositeObject) override;
protected:
    std::shared_ptr<BaseDrawer> drawer;
};


#endif //LAB_03_DRAWOBJECTVISITOR_H
