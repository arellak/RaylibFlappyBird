//
// Created by master on 25/03/2021.
//

#include "Player.h"
#include "obstacles/ObstacleManager.h"

Player::Player(NimbleTexture _texture, NimbleSound _sound, Vector2 _size, Vector2 _pos, Color _color) {
    texture = _texture;
    size = Vector2{(float) texture.texture.width, (float) texture.texture.height};
    pos = _pos;
    color = _color;
    velocity = Vector2{0, 0};
    curveVector = Vector2{0, 0};
    speed = 5;

    sound = _sound;
}

Player::Player(std::string _texPath, std::string _soundPath, Vector2 _size, Vector2 _pos, Color _color) {
    texturePath = _texPath;
    texture = createTexture();
    size = Vector2{(float) texture.texture.width, (float) texture.texture.height};
    pos = _pos;
    color = _color;

    velocity = Vector2{0, 0};
    curveVector = Vector2{0, 0};
    speed = 5;
    soundPath = _soundPath;
    sound = NimbleSound(_soundPath);
}

void Player::moveX() {
    int moveX = (int) (targetDestination.x - texture.pos.x);
    if(moveX != 0) {
        updateBody(moveX / MAX_VELOCITY, velocity.y);
    }
}

void Player::moveY() {
    int moveY = (int) (targetDestination.y - texture.pos.y);
    if(moveY != 0) {
        updateBody(velocity.x, moveY / MAX_VELOCITY);
    }
}

void Player::move() {
    moveX();
    moveY();
}

void Player::curveY(float _size) {
    curveVector.y += _size;
    pos.y -= curveVector.y;
}

void Player::curveX(float _size) {
    curveVector.x += _size;
    pos.x += curveVector.x;
}

void Player::curve(Vector2 _curveVector, float sizeX, float sizeY) {
    if(IsKeyPressed(KEY_SPACE)) {
        curveVector = Vector2{_curveVector.x, _curveVector.y};
        sound.play();
    }

    if(curveVector.x > 0 || curveVector.y > 0) {
        curveX(sizeX);
        curveY(sizeY);
    }
}

void Player::applyGravitation() {
    updateBody(0.0f, 9.81f);
}

void Player::moveWithKeys() {
    moveRight();
    moveLeft();
    updateBody((int) (velocity.x / MAX_VELOCITY), 0);

    moveDownwards();
    moveUpwards();
    updateBody(0, (int) (velocity.y / MAX_VELOCITY));

    brakeRight();
    brakeLeft();
    brakeDownwards();
    brakeUpwards();
}

void Player::moveLeft() {
    if(IsKeyDown(KEY_A)) {
        velocity.x -= speed;
    }
}

void Player::moveRight() {
    if(IsKeyDown(KEY_D)) {
        velocity.x += speed;
    }
}

void Player::moveUpwards() {
    if(IsKeyDown(KEY_W)) {
        velocity = Vector2{velocity.x, velocity.y - speed};
    }
}

void Player::moveDownwards() {
    if(IsKeyDown(KEY_S)) {
        velocity = Vector2{velocity.x, velocity.y + speed};
    }
}

void Player::brakeLeft() {
    if(IsKeyUp(KEY_A) && velocity.x < 0) {
        velocity.x += speed;
    }
}

void Player::brakeRight() {
    if(IsKeyUp(KEY_D) && velocity.x > 0) {
        velocity.x -= speed;
    }
}

void Player::brakeUpwards() {
    if(IsKeyUp(KEY_W) && velocity.y < 0) {
        velocity.y += speed;
    }
}

void Player::brakeDownwards() {
    if(IsKeyUp(KEY_S) && velocity.y > 0) {
        velocity.y -= speed;
    }
}

void Player::update() {
    applyGravitation();
    curve(Vector2{2.0f, 18.5f}, -0.05f, -0.5f);
    resetPos();
}

void Player::updateBody() {
    updateBody(velocity);
}

void Player::updateBody(float velocityX, float velocityY) {
    updateBody(Vector2{velocityX, velocityY});
}

void Player::updateBody(Vector2 _velocity) {
    pos.x += _velocity.x;
    pos.y += _velocity.y;

    texture.pos.x += _velocity.x;
    texture.pos.y += _velocity.y;
}

void Player::resetPos() {
    if(IsKeyPressed(KEY_LEFT_CONTROL)) {
        velocity = Vector2{0, 0};
        pos = Vector2{0, 400};
    }
    texture.pos = Vector2{pos.x, pos.y};
}

void Player::render() {
    texture.show();
}

NimbleTexture Player::createTexture() {
    NimbleTexture tmpTexture{texturePath, pos};
    return tmpTexture;
}

bool Player::scores() {
    Obstacle obstacle = ObstacleManager::getObstacle(0);

    bool checkX = pos.x > obstacle.posLower.x && pos.x < obstacle.posLower.x + obstacle.lowerPart.texture.width;
    bool checkY = pos.y < obstacle.posLower.y && pos.y > obstacle.posUpper.y + obstacle.upperPart.texture.height;

    return checkX && checkY;
}

bool Player::collides() {
    Obstacle obstacle = ObstacleManager::getObstacle(0);

    bool checkX = pos.x > obstacle.posLower.x && pos.x < obstacle.posLower.x + obstacle.lowerPart.texture.width;
    bool checkY = pos.y >= obstacle.posLower.y || pos.y <= obstacle.posUpper.y + obstacle.upperPart.texture.height;

    return checkX && checkY;
}
