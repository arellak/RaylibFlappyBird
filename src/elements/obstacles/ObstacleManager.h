//
// Created by master on 29/03/2021.
//

#ifndef RAYLIBB_OBSTACLEMANAGER_H
#define RAYLIBB_OBSTACLEMANAGER_H

#include <vector>
#include <string>
#include "Obstacle.h"

class ObstacleManager {
public:
    static inline std::vector<Obstacle> obstacles;

    static void render();
    static void update(float speed);

    static int createObstacle(float _posX, Vector2 _yPosses, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color);

    static Obstacle getObstacle(int index);
    static void removeFirstObstacle();

    static void createNew();
};


#endif //RAYLIBB_OBSTACLEMANAGER_H
