//
// Created by master on 31.03.21.
//

#include "GameConfig.h"

GameConfig::GameConfig(std::string _path) {
    path = _path;
    read();
}

void GameConfig::read() {
    std::ifstream reader(path);
    reader >> values;
    reader.close();
}

void GameConfig::read(std::string _path) {
    std::ifstream reader(_path);
    reader >> values;
    reader.close();
}
