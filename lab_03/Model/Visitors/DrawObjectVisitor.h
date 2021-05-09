//
// Created by Екатерина on 09.05.2021.
//

#ifndef LAB_03_DRAWOBJECTVISITOR_H
#define LAB_03_DRAWOBJECTVISITOR_H
#include "BaseVisitor.h"
#include "Drawer/BaseDrawer.h"

class DrawObjectVisitor : public BaseVisitor
{
public:
    DrawObjectVisitor(std::shared_ptr<BaseDrawer>& drawer);
    void visitCamera(BaseCamera &camera) override;
    void visitEdge(BaseEdge &edge) override;
    void visitFrameModel(FrameModel &model) override;
    void visitPoint(BasePoint &point) override;

protected:
    std::shared_ptr<BaseDrawer> drawer;
};


#endif //LAB_03_DRAWOBJECTVISITOR_H