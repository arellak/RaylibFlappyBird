cmake_minimum_required(VERSION 3.17)
project(Raylibb)
set(CMAKE_CXX_STANDARD 17)

# add libraries
include_directories(
        libs/raylib/include
)
link_directories(libs/raylib/lib)
add_subdirectory(libs/json/ ${CMAKE_CURRENT_BINARY_DIR}/nlohmann_json)


# add resources
file(GLOB resources "resources/*")
file(COPY ${resources} DESTINATION "${CMAKE_BINARY_DIR}/resources")

# add source files to executable
add_executable(
        RUNNABLE
        src/main.cpp
        src/elements/Player.cpp src/elements/Player.h
        src/texture/NimbleTexture.cpp src/texture/NimbleTexture.h
        src/logger/Logger.cpp src/logger/Logger.h
        src/elements/obstacles/Obstacle.cpp src/elements/obstacles/Obstacle.h
        src/sounds/NimbleSound.cpp src/sounds/NimbleSound.h
        src/elements/obstacles/ObstacleManager.cpp src/elements/obstacles/ObstacleManager.h
        src/elements/obstacles/ObstacleGenerator.cpp src/elements/obstacles/ObstacleGenerator.h
        src/config/GameConfig.cpp src/config/GameConfig.h
        src/level/Level.cpp src/level/Level.h src/level/LevelLoader.cpp src/level/LevelLoader.h src/level/LevelManager.h
        src/game/GameWindow.cpp src/game/GameWindow.h src/game/Game.cpp src/game/Game.h src/camera/NimbleCamera.cpp src/camera/NimbleCamera.h)


add_executable(
        TESTING
        src/tests/Test.cpp
        src/config/GameConfig.cpp src/config/GameConfig.h
        src/texture/NimbleTexture.cpp src/texture/NimbleTexture.h
        src/elements/obstacles/Obstacle.cpp src/elements/obstacles/Obstacle.h
        src/level/Level.cpp src/level/Level.h
        src/level/Level.cpp src/level/LevelLoader.cpp src/level/Level.cpp src/level/LevelLoader.h
        src/level/LevelManager.h
)

# link libraries to project
target_link_libraries(RUNNABLE raylib)
target_link_libraries(RUNNABLE nlohmann_json)

target_link_libraries(TESTING raylib)
target_link_libraries(TESTING nlohmann_json)