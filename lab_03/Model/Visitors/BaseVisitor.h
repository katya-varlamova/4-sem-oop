#ifndef BASEVISITOR_H
#define BASEVISITOR_H

class BaseCamera;
class Point;
class Edge;
class FrameModel;

class BaseVisitor
{
public:
    BaseVisitor() = default;
    virtual void visitPoint(Point& point) = 0;
    virtual void visitEdge(Edge& edge) = 0;
    virtual void visitCamera(BaseCamera& camera) = 0;
};

#endif // BASEVISITOR_H
