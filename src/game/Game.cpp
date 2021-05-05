//
// Created by rocketman on 05.05.21.
//

#include "Game.h"

Game::Game() {

}

void Game::init() {
    window.init();
}

void Game::showLevel() {
    Level level = LevelManager::levels.at(0);
}
