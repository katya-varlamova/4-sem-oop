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
    if (f == NULL)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "unable to open file");
}
void FileModelLoader::close()
{
    fclose(f);
}
std::shared_ptr<BaseObject> FileModelLoader::load()
{
    size_t pointsCount, edgesCount;
    double x, y, z;
    size_t fn, sn;
    if (fscanf(f, "%zu", &pointsCount) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points count)");
    std::vector<std::shared_ptr<Point>> points;
    if (fscanf(f, "%lf", &x) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points coordinates)");
    if (fscanf(f, "%lf", &y) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points coordinates)");
    if (fscanf(f, "%lf", &z) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points coordinates)");
    points.push_back(std::shared_ptr<Point>(new Point(x, y, z)));
    double minx = x, maxx = x, miny = y, maxy = y, minz = z, maxz = z;
    for (size_t i = 0; i < pointsCount - 1; i++)
    {
        if (fscanf(f, "%lf", &x) != 1)
            throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points coordinates)");
        if (fscanf(f, "%lf", &y) != 1)
            throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points coordinates)");
        if (fscanf(f, "%lf", &z) != 1)
            throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (points coordinates)");

        points.push_back(std::shared_ptr<Point>(new Point(x, y, z)));
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
    }
    if (fscanf(f, "%zu", &edgesCount) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (edges count)");

    std::vector<std::shared_ptr<Edge>> edges;
    for (size_t i = 0; i < edgesCount; i++)
    {
        if (fscanf(f, "%zu", &fn) != 1 || fn < 1)
            throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (edges)");
        if (fscanf(f, "%zu", &sn) != 1 || sn < 1)
            throw Load_Exception(__FILE__, __LINE__, __TIME__, "read model error (edges)");
        edges.push_back(std::shared_ptr<Edge>(new Edge( fn - 1, sn - 1)));
    }
    std::shared_ptr<BaseFrameModelBuilder> builder(new FrameModelBuilder(points, edges,  {x_center, y_center, z_center}));
    std::shared_ptr<BaseFrameModelDirector> director(new FrameModelDirector());
    return director->createFrameModel(builder);
}