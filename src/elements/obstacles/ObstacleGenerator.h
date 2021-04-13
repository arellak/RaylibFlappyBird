//
// Created by master on 31.03.21.
//

#ifndef RAYLIBB_OBSTACLEGENERATOR_H
#define RAYLIBB_OBSTACLEGENERATOR_H

#include "Obstacle.h"
#include "ObstacleManager.h"
#include <stdlib.h>
#include <time.h>

class ObstacleGenerator {
public:
    Obstacle generate(float _posX, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color);
    float randomGap();
};


#endif //RAYLIBB_OBSTACLEGENERATOR_H
