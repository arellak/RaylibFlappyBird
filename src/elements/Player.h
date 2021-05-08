//
// Created by master on 25/03/2021.
//

#ifndef RAYLIBB_PLAYER_H
#define RAYLIBB_PLAYER_H

#include "raylib.h"
#include "../texture/NimbleTexture.h"
#include "../logger/Logger.h"
#include "../sounds/NimbleSound.h"

class Player {
public:
   //  Rectangle body;
    Vector2 size;
    Vector2 pos;

    Color color;

    NimbleTexture texture;
    std::string texturePath;

    Vector2 targetDestination;
    Vector2 velocity;
    int speed;

    std::string soundPath;
    NimbleSound sound;

    Vector2 curveVector;

    int MAX_VELOCITY = 24;

    NimbleTexture createTexture();

    Player();
    Player(NimbleTexture _texture, NimbleSound _sound, Vector2 _pos, Color _color);
    Player(std::string _texPath, std::string _soundPath, Vector2 _pos, Color _color);

    void init(std::string _texPath, std::string _soundPath, Vector2 _pos, Color _color);

    void moveX();
    void moveY();
    void move();

    void curveY(float _size);
    void curveX(float _size);
    void curve(Vector2 _curveVector, float sizeX, float sizeY);

    void applyGravitation();

    void moveWithKeys();

    void updateBody();
    void updateBody(float _velocityX, float _velocityY);
    void updateBody(Vector2 _velocity);

    void moveLeft();
    void moveRight();
    void moveUpwards();
    void moveDownwards();
    void brakeUpwards();
    void brakeDownwards();
    void brakeLeft();
    void brakeRight();

    void resetPos();
    void render();
    void update();


    bool collides();

    bool scores();
};


#endif //RAYLIBB_PLAYER_H
