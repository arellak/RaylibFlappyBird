//
// Created by rocketman on 05.05.21.
//

#ifndef RAYLIBB_GAME_H
#define RAYLIBB_GAME_H

#include "raylib.h"
#include "GameWindow.h"
#include "../level/LevelManager.h"

class Game {
public:
    GameWindow window;


    Game();
    void init();
    void showLevel();
};


#endif //RAYLIBB_GAME_H
