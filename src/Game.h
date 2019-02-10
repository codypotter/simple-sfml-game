/**
 * @file Game.h
 * @author Cody Potter (me@codypotter.com)
 * @brief The header file for the Game class.
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Camera.h"
#include "Config.h"
#include "json/json.h"
#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief The game class is the most abstract container for the game.
 * 
 */
class Game {
    public:
        Game(); 
        Game(Config config);
        bool beginGameLoop(); 
        void loadAssets();
        bool loadTextures();
        bool loadFonts();
        void loadTilemaps();
        sf::Text formatText(std::string content, std::string fontName, int fontSize, int fontColor);
        void draw(sf::RenderWindow &window);
        std::string level = "LV\n01";

    private:
        Camera camera;                                  /**<  The main camera for the game. */
        Config config;                                  /**<  The starting game options.  */
        std::map<std::string, sf::Texture> textures;    /**<  A map of all the game textures */
        std::map<std::string, sf::Sprite> sprites;      /**<  A map of all the game sprites */
        std::map<std::string, sf::Font> fonts;          /**<  A map of all the game fonts */
        std::map<std::string, sf::Text> texts;          /**<  A map of all the game texts */
        int score = 0;
};