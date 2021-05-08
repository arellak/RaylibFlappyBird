//
// Created by rocketman on 05.05.21.
//

#include "NimbleCamera.h"

NimbleCamera::NimbleCamera() {
    // width = GameConfig::values.at("width");
    // height = GameConfig::values.at("height");
}

void NimbleCamera::follow(Player _player, float width, float height) {
    cam.target = (Vector2) {_player.pos.x + 20, _player.pos.y + 20};
    cam.offset = (Vector2) {width/2.0f, height/2.0f};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;
}