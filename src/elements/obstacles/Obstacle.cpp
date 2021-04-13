//
// Created by master on 28/03/2021.
//

#include "Obstacle.h"

Obstacle::Obstacle(float _posX, Vector2 _yPosses, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color) {
    yPosses = _yPosses;
    posUpper = Vector2{_posX, _yPosses.x};
    posLower = Vector2{_posX, _yPosses.y};
    upperTexturePath = _upperTexturePath;
    lowerTexturePath = _lowerTexturePath;
    initTextures();

    sizeUpperPart = Vector2{(float) upperPart.texture.width, (float) upperPart.texture.height};
    sizeLowerPart = Vector2{(float) lowerPart.texture.width, (float) lowerPart.texture.height};

    posX = _posX;

    color = _color;
}

void Obstacle::initTextures() {
    upperPart = NimbleTexture(upperTexturePath);
    lowerPart = NimbleTexture(lowerTexturePath);
}

void Obstacle::initTexturePositions() {
    upperPart.pos = posUpper;
    lowerPart.pos = posLower;
}

void Obstacle::render() {
    upperPart.show();
    lowerPart.show();
}

void Obstacle::update(float speed) {
    posUpper.x += speed;
    posLower.x += speed;
    upperPart.pos.x += speed;
    lowerPart.pos.x += speed;
}

Obstacle::Obstacle() {

}
