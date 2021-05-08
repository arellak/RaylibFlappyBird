#include "raylib.h"
#include "logger/Logger.h"
#include "game/Game.h"
#include "config/GameConfig.h"
#include "elements/Player.h"
#include "camera/NimbleCamera.h"

int main() {
    Logger::path = "Game.log";
    Logger::clearLogger();

    GameConfig::read("resources/gameConfig/gameConfig.json");
    Game game;

    // std::string _texPath, std::string _soundPath, Vector2 _pos, Color _color
    Player player("resources/bird.png", "resources/blub.wav", Vector2{220, 50}, BLACK);

    // float _posX, Vector2 _yPosses, std::string _upperTexturePath, std::string _lowerTexturePath, Color _color
    Obstacle o(game.window.width - 50, {-100, 400}, "resources/pipe-green-reversed.png", "resources/pipe-green.png", GREEN);
    o.initTexturePositions();

    NimbleCamera camera;
    while(!WindowShouldClose()) {
        camera.follow(player, game.window.width, game.window.height);

        BeginDrawing();
        game.window.backgroundColor(GRAY);

        BeginMode2D(camera.cam);
            o.render();
            player.update();
            player.render();
        EndMode2D();

        EndDrawing();
    }

    game.window.dispatch();

    return 0;
}