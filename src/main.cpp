#include "raylib.h"
#include "elements/obstacles/ObstacleManager.h"
#include "elements/Player.h"

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 500

bool paused = false;

void gameOver() {
    paused = true;
    DrawText("GAME OVER", SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2, 25, BLACK);
}

int main() {
    Logger::path = "Game.log";
    Logger::clearLogger();

    Image windowIcon = LoadImage("resources/desktopIcon.png");

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    SetWindowIcon(windowIcon);
    SetTargetFPS(50);

    Player player("resources/bird.png",
                  "resources/blub.wav",
                  Vector2{50, 50},
                  Vector2{0, 100},
                  GRAY);

    ObstacleManager::createObstacle(
            400,
            Vector2{-100, 400},
            "resources/pipe-green-reversed.png",
            "resources/pipe-green.png",
            GREEN);

    int scoreCount = 0;
    int otherScoureCount = 0;
    while(!WindowShouldClose()) {
        BeginDrawing();

        if(IsKeyPressed(KEY_P)) {
            paused = !paused;
        }

        if(player.collides()) {
            gameOver();
        }

        if(player.scores()) {
            otherScoureCount++;
            if(otherScoureCount == 8) {
                scoreCount++;
                otherScoureCount = 0;
            }
        }

        std::string score("Score: ");
        score.append(std::to_string(scoreCount));
        DrawText(score.c_str(), 50, 10, 20, BLACK);

        if(!paused) {
            // update
            player.update();
            ObstacleManager::update(-5);
            ObstacleManager::createNew();
        }

        // render
        player.render();
        ObstacleManager::render();
        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}