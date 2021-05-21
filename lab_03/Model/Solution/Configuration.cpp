//
// Created by Екатерина on 21.05.2021.
//

#include "Configuration.h"
void Configuration::readConfiguration(std::string name)
{
    std::ifstream fin(name);
    std::string tmp;
    fin >> tmp;
    graphicsLibrary = tmp;
    fin >> tmp;
    dataSource = tmp;
}
std::string Configuration::getDataSource()
{
    return dataSource;
}
std::string Configuration::getGraphicsLibrary()
{
    return graphicsLibrary;
}