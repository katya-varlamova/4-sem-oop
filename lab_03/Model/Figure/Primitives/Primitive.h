//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_PRIMITIVE_H
#define LAB_03_PRIMITIVE_H

#include "Point/Point.h"
#include "Edge/Edge.h"
class Primitive {
public:
    void addPoint(std::shared_ptr<Point> point);
    void addEdge(std::shared_ptr<Edge> edge);

    void transform(Matrix<double> &transformMatrix);
    std::vector<std::shared_ptr<Point>> getPoints();
    std::vector<std::shared_ptr<Edge>> getEdges();

protected:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<Edge>> edges;
};


#endif //LAB_03_PRIMITIVE_H
