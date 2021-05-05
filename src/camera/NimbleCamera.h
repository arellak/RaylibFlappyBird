//
// Created by rocketman on 05.05.21.
//

#ifndef RAYLIBB_NIMBLECAMERA_H
#define RAYLIBB_NIMBLECAMERA_H

#include "raylib.h"
#include "../elements/Player.h"

class NimbleCamera {
public:
    Camera2D cam;

    NimbleCamera();
    void init();
    void follow(Player player, int width, int height);
};


#endif //RAYLIBB_NIMBLECAMERA_H
