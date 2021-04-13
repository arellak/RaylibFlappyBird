//
// Created by master on 29/03/2021.
//

#include "NimbleSound.h"

NimbleSound::NimbleSound() {

}

NimbleSound::NimbleSound(std::string _path) {
    path = _path;
    InitAudioDevice();
    sound = LoadSound(path.c_str());
}

void NimbleSound::play() {
    PlaySound(sound);
}

void NimbleSound::unload() {
    UnloadSound(sound);
}
