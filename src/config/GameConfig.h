//
// Created by master on 31.03.21.
//

#ifndef RAYLIBB_GAMECONFIG_H
#define RAYLIBB_GAMECONFIG_H

#include <fstream>
#include <map>
#include <string>
#include "json.hpp"
#include <any>

class GameConfig {
public:
    std::string path;
    // static inline std::map<std::string, std::any> values;
    static inline nlohmann::json values;

    GameConfig(std::string _path);

    void read();
    void init();
};


#endif //RAYLIBB_GAMECONFIG_H
