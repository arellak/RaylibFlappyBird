//
// Created by rocketman on 05.05.21.
//

#include "GameWindow.h"

GameWindow::GameWindow() {
    init();
}

void GameWindow::init() {
    title = GameConfig::values.at("title");
    width = GameConfig::values.at("width");
    height = GameConfig::values.at("height");
    std::string iconPath(GameConfig::values.at("title"));
    icon = LoadImage(iconPath.c_str());
    targetFps = GameConfig::values.at("targetFps");

    InitWindow(width, height, title.c_str());
    SetWindowIcon(icon);
    SetTargetFPS(targetFps);
}

void GameWindow::dispatch() {
    CloseWindow();
}

void GameWindow::backgroundColor(Color color) {
    ClearBackground(color);
}

