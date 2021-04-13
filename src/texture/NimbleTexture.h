//
// Created by master on 25/03/2021.
//

#ifndef RAYLIBB_NIMBLETEXTURE_H
#define RAYLIBB_NIMBLETEXTURE_H

#include <string>
#include "raylib.h"

class NimbleTexture {
public:
    NimbleTexture(std::string _path);

    std::string path;
    Texture2D texture;
    Vector2 pos;

    NimbleTexture();
    NimbleTexture(std::string _path, Vector2 _pos);

    void unload();
    void show();
};


#endif //RAYLIBB_NIMBLETEXTURE_H
