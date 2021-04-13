//
// Created by master on 04.04.21.
//

#include "LevelLoader.h"

void LevelLoader::load(std::string name) {
    std::string path("resoruces/level/");
    path.append(name).append("level");

    Level tmpLevel;
    std::ifstream reader(path.c_str());
    nlohmann::json j;
    reader >> j;

    std::string levelName = j.at("levelName");
    float speed = j.at("playerSpeed");

    tmpLevel.speed = speed;
    tmpLevel.name = levelName;

    // Load settings from GameConfig
    std::string playerTheme = GameConfig::values.at("playerTheme");
    std::string obstacleTheme = GameConfig::values.at("obstacleTheme");

    // set paths for textures(pipes and player and in the future background etc)
    std::string obstacleUpperTexturePath("resources/textures/obstacles/");
    obstacleUpperTexturePath
            .append(obstacleTheme)
            .append("/pipe-")
            .append(obstacleTheme)
            .append(".png");

    std::string obstacleLowerTexturePath("resources/textures/obstacles/");
    obstacleLowerTexturePath
            .append(obstacleTheme)
            .append("/pipe-")
            .append(obstacleTheme)
            .append("-reversed.png");

    std::string birdTexturePath("resources/textures/player/");
    birdTexturePath
            .append(playerTheme)
            .append("/")
            .append(playerTheme)
            .append("bird.png");

    /*
     * looped über jeden Eintrag in obstacles, also über alle obstacles und so bekommt man dann
     * dementsprechend auch die Werte der einzelnen Obstacles
     */
    for(auto &[key, value] : j.at("obstacles").items()) {
        Obstacle tmpObstacle;
        tmpObstacle.name = key;

        // TEXTURES
        tmpObstacle.upperTexturePath = obstacleUpperTexturePath;
        tmpObstacle.lowerTexturePath = obstacleLowerTexturePath;
        tmpObstacle.initTextures();

        // POSITIONS
        float spaceFromTop = j.at("obstacles").at(key).at("spaceFromTop");
        float spaceFromBottom = j.at("obstacles").at(key).at("spaceFromBottom");
        float distanceToNext = j.at("obstacles").at(key).at("distanceToNext");

        Vector2 yPosses{
                spaceFromTop - tmpObstacle.upperPart.texture.height,
                ((float) GameConfig::values.at("height")) - spaceFromBottom
        };
        tmpObstacle.yPosses = yPosses;

        tmpObstacle.posUpper = Vector2{(float) GameConfig::values.at("width"), yPosses.x};
        tmpObstacle.posLower = Vector2{(float) GameConfig::values.at("width"), yPosses.y};

        tmpObstacle.sizeUpperPart = Vector2{(float) tmpObstacle.upperPart.texture.width, (float) tmpObstacle.upperPart.texture.height};
        tmpObstacle.sizeLowerPart = Vector2{(float) tmpObstacle.lowerPart.texture.width, (float) tmpObstacle.lowerPart.texture.height};

        tmpObstacle.initTexturePositions();
        tmpObstacle.distanceToNext = distanceToNext;

        tmpLevel.obstacles.push_back(tmpObstacle);
    }
}

void LevelLoader::load() {
    std::string path("resoruces/level/");
    for(auto &entry : std::filesystem::directory_iterator(path)) {
        load(path.substr(16));

        /*
        Level tmpLevel;
        std::ifstream reader(entry.path().c_str());
        nlohmann::json j;
        reader >> j;

        std::string levelName = j.at("levelName");
        float speed = j.at("playerSpeed");

        tmpLevel.speed = speed;
        tmpLevel.name = levelName;

        // Load settings from GameConfig
        std::string playerTheme = GameConfig::values.at("playerTheme");
        std::string obstacleTheme = GameConfig::values.at("obstacleTheme");

        // set paths for textures(pipes and player and in the future background etc)
        std::string obstacleUpperTexturePath("resources/textures/obstacles/");
        obstacleUpperTexturePath
            .append(obstacleTheme)
            .append("/pipe-")
            .append(obstacleTheme)
            .append(".png");

        std::string obstacleLowerTexturePath("resources/textures/obstacles/");
        obstacleLowerTexturePath
            .append(obstacleTheme)
            .append("/pipe-")
            .append(obstacleTheme)
            .append("-reversed.png");

        std::string birdTexturePath("resources/textures/player/");
        birdTexturePath
            .append(playerTheme)
            .append("/")
            .append(playerTheme)
            .append("bird.png");


         //looped über jeden Eintrag in obstacles, also über alle obstacles und so bekommt man dann
         //dementsprechend auch die Werte der einzelnen Obstacles

         for(auto &[key, value] : j.at("obstacles").items()) {
            Obstacle tmpObstacle;
            tmpObstacle.name = key;

            // TEXTURES
            tmpObstacle.upperTexturePath = obstacleUpperTexturePath;
            tmpObstacle.lowerTexturePath = obstacleLowerTexturePath;
            tmpObstacle.initTextures();

            // POSITIONS
            float spaceFromTop = j.at("obstacles").at(key).at("spaceFromTop");
            float spaceFromBottom = j.at("obstacles").at(key).at("spaceFromBottom");
            float distanceToNext = j.at("obstacles").at(key).at("distanceToNext");

            Vector2 yPosses{
                    spaceFromTop - tmpObstacle.upperPart.texture.height,
                    ((float) GameConfig::values.at("height")) - spaceFromBottom
            };
            tmpObstacle.yPosses = yPosses;

            tmpObstacle.posUpper = Vector2{(float) GameConfig::values.at("width"), yPosses.x};
            tmpObstacle.posLower = Vector2{(float) GameConfig::values.at("width"), yPosses.y};

            tmpObstacle.sizeUpperPart = Vector2{(float) tmpObstacle.upperPart.texture.width, (float) tmpObstacle.upperPart.texture.height};
            tmpObstacle.sizeLowerPart = Vector2{(float) tmpObstacle.lowerPart.texture.width, (float) tmpObstacle.lowerPart.texture.height};

            tmpObstacle.initTexturePositions();
            tmpObstacle.distanceToNext = distanceToNext;

            tmpLevel.obstacles.push_back(tmpObstacle);
        }
         */
    }
}