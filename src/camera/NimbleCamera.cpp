//
// Created by rocketman on 05.05.21.
//

#include "NimbleCamera.h"

NimbleCamera::NimbleCamera() {

}

void NimbleCamera::init() {

}

void NimbleCamera::follow(Player player, int width, int height) {
    cam.target = (Vector2) {player.pos.x, (float) height/2};
    cam.offset = (Vector2) {(float) width/2, (float) height/2};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;
}
