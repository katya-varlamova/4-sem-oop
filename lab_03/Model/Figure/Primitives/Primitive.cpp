//
// Created by Екатерина on 21.05.2021.
//

#include "Primitive.h"
void Primitive::addPoint(std::shared_ptr<Point> point)
{
    points.push_back(point);
}
void Primitive::addEdge(std::shared_ptr<Edge> edge)
{
    edges.push_back(edge);
}
void Primitive::transform(Matrix<double> &transformMatrix)
{
    for (auto &point : points)
        point->transform(transformMatrix);
}
std::vector<std::shared_ptr<Point>> Primitive::getPoints()
{
    return points;
}
std::vector<std::shared_ptr<Edge>> Primitive::getEdges()
{
    return edges;
}