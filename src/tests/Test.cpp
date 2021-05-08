//
// Created by master on 31.03.21.
//

#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>
#include "../config/GameConfig.h"
#include <vector>
#include <filesystem>
#include <any>
#include "../level/LevelLoader.h"
#include "../level/LevelManager.h"

int main() {
    GameConfig gc("resources/gameConfig/gameConfig.json");
    LevelLoader loader;
    loader.load();


    // printf("%s\n", LevelManager::levels.at(0).name.c_str());

    // gc.read();

    // printf("%s", GameConfig::values["width"].c_str());
    /*
    std::string path("resources/level/");
    for(auto &entry : std::filesystem::directory_iterator(path)) {
        std::string p(entry.path());
        p.substr(16);
        printf("%s\n", p.substr(16).c_str());
    }
     */


    return 0;
}