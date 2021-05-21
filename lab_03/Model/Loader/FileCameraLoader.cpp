//
// Created by Екатерина on 19.05.2021.
//

#include "FileCameraLoader.h"
FileCameraLoader::FileCameraLoader(FILE *f)
{
    this->f = f;
}
void FileCameraLoader::open(std::string name)
{
    f = fopen(name.c_str(), "r");
}
void FileCameraLoader::close()
{
    fclose(f);
}
std::shared_ptr<BaseObject> FileCameraLoader::load()
{
    double distanse;
    fscanf(f, "%lf", &distanse);
    std::vector<double> offset;
    double tmp;
    for (int i = 0; i < 3; i++)
    {
        fscanf(f, "%lf", &tmp);
        offset.push_back(tmp);
    }
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory);
    return std::dynamic_pointer_cast<BaseObject>(factory->createCamera(distanse, offset));
}