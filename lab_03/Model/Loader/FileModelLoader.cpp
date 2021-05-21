//
// Created by Екатерина on 19.05.2021.
//

#include "FileModelLoader.h"
FileModelLoader::FileModelLoader(FILE *f)
{
    this->f = f;
}
void FileModelLoader::open(std::string name)
{
    f = fopen(name.c_str(), "r");
}
void FileModelLoader::close()
{
    fclose(f);
}
std::shared_ptr<BaseObject> FileModelLoader::load()
{
    size_t pointsCount, edgesCount, modelsCount;
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory);
    double x, y, z;
    size_t fn, sn;
    fscanf(f, "%zu", &pointsCount);
    std::vector<std::shared_ptr<Point>> points;
    fscanf(f, "%lf", &x);
    fscanf(f, "%lf", &y);
    fscanf(f, "%lf", &z);
    points.push_back(factory->createPoint(x, y, z, {0, 0, 0}));
    double minx = x, maxx = x, miny = y, maxy = y, minz = z, maxz = z;
    for (size_t i = 0; i < pointsCount - 1; i++)
    {
        fscanf(f, "%lf", &x);
        fscanf(f, "%lf", &y);
        fscanf(f, "%lf", &z);
        points.push_back(factory->createPoint(x, y, z, {0, 0, 0}));
        if (x > maxx)
            maxx = x;
        if (x < minx)
            minx = x;

        if (y > maxy)
            maxy = y;
        if (y < miny)
            miny = y;

        if (z > maxz)
            maxz = z;
        if (z < minz)
            minz = z;
    }
    double x_center = (minx + maxx) / 2;
    double y_center = (miny + maxy) / 2;
    double z_center = (minz + maxz) / 2;

    for (size_t i = 0; i < pointsCount; i++)
    {
        points[i]->setX(points[i]->getX() - x_center);
        points[i]->setY(points[i]->getY() - y_center);
        points[i]->setZ(points[i]->getZ() - z_center);
        points[i]->setOffset(std::vector<double>({x_center, y_center, z_center}));
    }
    fscanf(f, "%zu", &edgesCount);

    std::vector<std::shared_ptr<Edge>> edges;
    for (size_t i = 0; i < edgesCount; i++)
    {
        fscanf(f, "%zu", &fn);
        fscanf(f, "%zu", &sn);
        edges.push_back(factory->createEdge( points[fn - 1]->clone(),
                                             points[sn - 1]->clone(),
                                             {x_center, y_center, z_center}));
    }
    return factory->createFrameModel(points, edges);
}