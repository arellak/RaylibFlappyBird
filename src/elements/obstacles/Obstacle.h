//
// Created by master on 28/03/2021.
//

#ifndef RAYLIBB_OBSTACLE_H
#define RAYLIBB_OBSTACLE_H

#include <string>
#include "../../texture/NimbleTexture.h"

class Obstacle {
public:
    std::string name;
    NimbleTexture upperPart;
    NimbleTexture lowerPart;

    std::string upperTexturePath;
    std::string lowerTexturePath;

    Vector2 posUpper;
    Vector2 posLower;
    Vector2 yPosses;

    Vector4 freePart;

    Vector2 sizeUpperPart;
    Vector2 sizeLowerPart;
    float posX;

    std::string theme;
    float distanceToNext;

    Color color;
    Obstacle(float _posX, Vector2 _yPosses, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color);
    Obstacle();

    void initTextures();

    void update(float speed);
    void render();

    void initTexturePositions();
};


#endif //RAYLIBB_OBSTACLE_H