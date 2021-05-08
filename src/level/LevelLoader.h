//
// Created by master on 04.04.21.
//

#ifndef RAYLIBB_LEVELLOADER_H
#define RAYLIBB_LEVELLOADER_H

#include "Level.h"
#include "nlohmann/json.hpp"
#include <vector>
#include <filesystem>
#include <string>
#include <fstream>
#include "../config/GameConfig.h"
#include "LevelManager.h"

class LevelLoader {
public:
    std::vector<Level> level;

    void load(std::string name);
    void load();
};


#endif //RAYLIBB_LEVELLOADER_H
