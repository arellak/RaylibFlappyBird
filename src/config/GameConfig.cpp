//
// Created by master on 31.03.21.
//

#include "GameConfig.h"

GameConfig::GameConfig(std::string _path) {
    path = _path;
    read();
}

void GameConfig::init() {
    std::fstream reader;
    reader.open(path);

    std::string line;
    std::string delimiter("=");

    while(getline(reader, line)) {
        std::string key(line.substr(0, line.find(delimiter)));
        std::string value(line.substr(line.find(delimiter)+1, line.size()));
        values[key] = value;
    }

    reader.close();
}

void GameConfig::read() {
    std::ifstream reader(path);
    reader >> values;
    reader.close();
}
