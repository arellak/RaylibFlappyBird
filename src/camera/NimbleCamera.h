//
// Created by rocketman on 05.05.21.
//

#ifndef RAYLIBB_NIMBLECAMERA_H
#define RAYLIBB_NIMBLECAMERA_H

#include "raylib.h"
#include "../elements/Player.h"
#include "../config/GameConfig.h"

class NimbleCamera {
public:
    Camera2D cam;
    // float width;
    // float height;

    NimbleCamera();
    void follow(Player _player, float width, float height);
};


#endif //RAYLIBB_NIMBLECAMERA_H
