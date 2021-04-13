//
// Created by master on 29/03/2021.
//

#include "ObstacleManager.h"

void ObstacleManager::render() {
    for(auto &obstacle : obstacles) {
        obstacle.render();
    }
}

void ObstacleManager::update(float speed) {
    for(auto &obstacle : obstacles) {
        obstacle.update(speed);
    }
}

int ObstacleManager::createObstacle(float _posX, Vector2 _yPosses, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color) {
    Obstacle tmpObstacle(_posX, _yPosses, _upperTexturePath, _lowerTexturePath, _color);
    obstacles.push_back(tmpObstacle);
    return obstacles.size()-1;
}

Obstacle ObstacleManager::getObstacle(int index) {
    return obstacles.at(index);
}

void ObstacleManager::removeFirstObstacle() {
    UnloadTexture(getObstacle(0).upperPart.texture);
    UnloadTexture(getObstacle(0).lowerPart.texture);
    obstacles.pop_back();
}

void ObstacleManager::createNew() {
    Obstacle obstacle = getObstacle(0);
    if(obstacle.upperPart.pos.x < -obstacle.upperPart.texture.width) {
        srand(time(NULL));
        float gap = rand() % 400 + 300;
        while(gap < 300 || gap > 425) {
            gap = rand() % 350 + 150;
        }

        removeFirstObstacle();
        createObstacle(
                600,
                Vector2{-gap/2.5f, gap/1.05f},
                "resources/pipe-green-reversed.png",
                "resources/pipe-green.png",
                GREEN);
    }
}
