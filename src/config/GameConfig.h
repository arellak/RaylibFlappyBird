//
// Created by master on 31.03.21.
//

#ifndef RAYLIBB_GAMECONFIG_H
#define RAYLIBB_GAMECONFIG_H

#include <fstream>
#include <string>
#include "nlohmann/json.hpp"

class GameConfig {
public:
    std::string path;
    static inline nlohmann::json values;

    GameConfig();
    GameConfig(std::string _path);

    void read();
    static void read(std::string path);
};


#endif //RAYLIBB_GAMECONFIG_H
