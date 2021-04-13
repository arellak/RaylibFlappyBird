//
// Created by master on 25/03/2021.
//

#include "NimbleTexture.h"

NimbleTexture::NimbleTexture() {

}

NimbleTexture::NimbleTexture(std::string _path, Vector2 _pos) {
    path = _path;
    pos = _pos;
    texture = LoadTexture(path.c_str());
}

NimbleTexture::NimbleTexture(std::string _path) {
    path = _path;
    texture = LoadTexture(path.c_str());
}

void NimbleTexture::unload() {
    UnloadTexture(texture);
}

void NimbleTexture::show() {
    DrawTexture(texture, (int) pos.x, (int) pos.y, WHITE);
}
