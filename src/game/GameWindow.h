//
// Created by rocketman on 05.05.21.
//

#ifndef RAYLIBB_GAMEWINDOW_H
#define RAYLIBB_GAMEWINDOW_H

#include <string>
#include "raylib.h"
#include "../config/GameConfig.h"

class GameWindow {
public:
    int width;
    int height;
    std::string title;

    int targetFps;

    Image icon;

    GameWindow();

    void init();
    void dispatch();
    void backgroundColor(Color color);
};


#endif //RAYLIBB_GAMEWINDOW_H
