//
// Created by Екатерина on 21.05.2021.
//

#include "FileLoaderCreator.h"
std::shared_ptr<BaseLoader> FileLoaderCreator::createLoader()
{
    return std::shared_ptr<BaseLoader>(new FileSceneLoader());
}