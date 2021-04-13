//
// Created by master on 03.04.21.
//

#ifndef RAYLIBB_LEVEL_H
#define RAYLIBB_LEVEL_H

#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "../elements/obstacles/Obstacle.h"

class Level {
public:
    std::string name;
    float speed;
    std::string theme;
    std::vector<Obstacle> obstacles;

    Level();
};


#endif //RAYLIBB_LEVEL_H
