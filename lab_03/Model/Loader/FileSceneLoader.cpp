//
// Created by Екатерина on 18.05.2021.
//

#include "FileSceneLoader.h"
FileSceneLoader::FileSceneLoader(FILE *f)
{
    this->f = f;
}
void FileSceneLoader::open(std::string name)
{
    f = fopen(name.c_str(), "r");
    if (f == NULL)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "unable to open file");
}
void FileSceneLoader::close()
{
    fclose(f);
}
std::shared_ptr<BaseObject> FileSceneLoader::load()
{
    std::shared_ptr<BaseSceneBuilder> builder(new SceneBuilder(std::shared_ptr<BaseCamera>()));
    std::shared_ptr<BaseSceneDirector> director(new SceneDirector());
    scene = director->createScene(builder);

    FileModelLoader modelLoader(f);
    int modelsCount;
    if (fscanf(f, "%d", &modelsCount) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read scene error (models count)");
    for (int i = 0; i < modelsCount; i++)
        scene->addObject(modelLoader.load());

    int camerasCount;
    FileCameraLoader cameraLoader(f);
    if (fscanf(f, "%d", &camerasCount) != 1)
        throw Load_Exception(__FILE__, __LINE__, __TIME__, "read scene error (cameras count)");
    for (int i = 0; i < camerasCount; i++)
        scene->addObject(cameraLoader.load());

    scene->setCamera(std::dynamic_pointer_cast<BaseCamera>(cameraLoader.load()));
    return std::dynamic_pointer_cast<BaseObject>(scene);
}