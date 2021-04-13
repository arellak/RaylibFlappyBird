//
// Created by master on 29/03/2021.
//

#ifndef RAYLIBB_NIMBLESOUND_H
#define RAYLIBB_NIMBLESOUND_H

#include <string>
#include "raylib.h"

class NimbleSound {
public:
    NimbleSound(std::string _path);

    NimbleSound();

    std::string path;
    Sound sound;

    void play();
    void unload();
};


#endif //RAYLIBB_NIMBLESOUND_H
