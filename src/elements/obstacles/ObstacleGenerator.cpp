//
// Created by master on 31.03.21.
//

#include "ObstacleGenerator.h"

/**
 *
 * @param _posX the x value of the obstacle
 * @param _upperTexturePath path to the upper texture of the obstacle
 * @param _lowerTexturePath path to the lower texture of the obstacle
 * @param _color background color when texture is fucked up i guess
 * @return new Obstacle with given values
 */
Obstacle ObstacleGenerator::generate(float _posX, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color) {
    // float _posX, Vector2 _yPosses, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color
    Obstacle o(_posX, Vector2{randomGap()/2.5f, randomGap()}, _upperTexturePath, _lowerTexturePath, _color);
    // read values from level files
    return o;
}

/**
 * @return pseudo random number
 */
float ObstacleGenerator::randomGap() {
    srand(time(NULL));
    float gap = rand() % 400 + 300;
    while(gap < 300 || gap > 425) {
        gap = rand() % 350 + 150;
    }
    return gap;
}
