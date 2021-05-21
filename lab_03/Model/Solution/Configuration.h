//
// Created by Екатерина on 21.05.2021.
//

#ifndef LAB_03_CONFIGURATION_H
#define LAB_03_CONFIGURATION_H

#include <string>
#include <fstream>
class Configuration {
public:
    Configuration() = default;
    void readConfiguration(std::string name);
    std::string getDataSource();
    std::string getGraphicsLibrary();

protected:
    std::string dataSource;
    std::string graphicsLibrary;

};


#endif //LAB_03_CONFIGURATION_H
