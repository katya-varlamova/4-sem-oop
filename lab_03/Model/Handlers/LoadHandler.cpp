#include "LoadHandler.h"

LoadHandler::LoadHandler(const char *filename)
{
    this->filename = filename;
}
void LoadHandler::handle(std::shared_ptr<BaseScene> &scene)
{
    FILE *f = fopen(filename, "r");
    size_t pointsCount, edgesCount, modelsCount;
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory);
    double x, y, z;
    size_t fn, sn;
    fscanf(f, "%zu", &modelsCount);
    for (size_t j = 0; j < modelsCount; j++)
    {
        fscanf(f, "%zu", &pointsCount);
        std::vector<std::shared_ptr<BasePoint>> points;
        fscanf(f, "%lf", &x);
        fscanf(f, "%lf", &y);
        fscanf(f, "%lf", &z);
        points.push_back(factory->createPoint(x, y, z));
        double minx = x, maxx = x, miny = y, maxy = y, minz = z, maxz = z;
        for (size_t i = 0; i < pointsCount - 1; i++)
        {
            fscanf(f, "%lf", &x);
            fscanf(f, "%lf", &y);
            fscanf(f, "%lf", &z);
            points.push_back(factory->createPoint(x, y, z));
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

        std::vector<std::shared_ptr<BaseEdge>> edges;
        for (size_t i = 0; i < edgesCount; i++)
        {
            fscanf(f, "%zu", &fn);
            fscanf(f, "%zu", &sn);
            edges.push_back(factory->createEdge( std::dynamic_pointer_cast<BasePoint>(points[fn - 1]->clone()),
                                                 std::dynamic_pointer_cast<BasePoint>(points[sn - 1]->clone())));
        }
        std::shared_ptr<BaseObject> obj = factory->createFrameModel(points, edges);
        scene->addObject(obj);
    }
    fclose(f);
}
