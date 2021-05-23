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
    if (f == NULL)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "unable to open file");
}
void FileCameraLoader::close()
{
    fclose(f);
}
std::shared_ptr<BaseObject> FileCameraLoader::load()
{
    double distanse;
    if (fscanf(f, "%lf", &distanse) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read camera error");
    std::vector<double> offset;
    double tmp;
    for (int i = 0; i < 3; i++)
    {
        if (fscanf(f, "%lf", &tmp) != 1)
            throw Load_Exception(__FILE__, __LINE__, __TIME__, "read camera error");;
        offset.push_back(tmp);
    }
    std::shared_ptr<BaseObjectFactory> factory(new ObjectFactory);
    return std::dynamic_pointer_cast<BaseObject>(factory->createCamera(distanse, offset));
}