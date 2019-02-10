/**
 * @file Game.cpp
 * @author Cody Potter (me@codypotter.com)
 * @brief Game object methods
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include"Game.h"

/**
 * @brief Construct a new Game:: Game object
 * 
 * @param config 
 */
Game::Game(Config config) {
	this->config = config;
	this->camera = Camera(config.resolution.width, config.resolution.height);
	loadAssets();
	beginGameLoop();
}

/**
 * @brief Construct a new Game:: Game object
 * 
 * It is not recommended to use the default constructor because it defaults to arbitrary values.
 */
Game::Game() {
	this->config = Config();
    camera = Camera(800, 600);
    loadAssets();
    beginGameLoop();
}

/**
 * @brief Loads the textures in the assets folder. 
 * 			
 * Must hard-code the file names to load.
 * 
 * @return true when finished loading all textures successfully.
 * @return false when failing to load any textures.
 */
bool Game::loadTextures() {
	// just add names of textures inside ./assets folder to this vector
	std::vector<std::string> textureNames = {"game-spritesheet.png"};

	while (!textureNames.empty()) {
		sf::Texture texture;

		if (!texture.loadFromFile("./assets/" + textureNames.back())) {
			textureNames.pop_back();
			std::cerr << "Error loading image." << std::endl;
			return false;
		}
		
		textures[textureNames.back()] = texture;
		textureNames.pop_back();
	}

    return true;
}

/**
 * @brief Loads all the fonts in the fontNames parameter
 * 
 * @return true 
 * @return false 
 */
bool Game::loadFonts() {
	// just add names of fonts inside ./assets folder to this vector
	std::vector<std::string> fontNames = {"gohufont-11.bdf"};

	while (!fontNames.empty()) {
		sf::Font font;

		if (!font.loadFromFile("./assets/" + fontNames.back())) {
			fontNames.pop_back();
			std::cerr << "Error loading font." << std::endl;
			return false;
		}
		const_cast<sf::Texture&>(font.getTexture(11)).setSmooth(false);
		
		fonts[fontNames.back()] = font;
		fontNames.pop_back();
	}

    return true;
}

void Game::loadTilemaps() {
	Json::Value root;

	std::ifstream tilemapDoc("game-tilemap.json", std::ifstream::binary);
	tilemapDoc >> root;
}

/**
 * @brief Loads all game assets
 * 
 */
void Game::loadAssets() {
	loadFonts();
	loadTextures();
	loadTilemaps();
}

/**
 * @brief Sets formatting for a Text object
 * 
 * @param content is the text content of the Text object
 * @param fontName is the name of the font to use (must be previously loaded)
 * @param fontSize is the size of the font in pixels
 * @param fontColor is the color of the font
 * @return sf::Text is the formatted Text object
 */
sf::Text Game::formatText(std::string content, std::string fontName, int fontSize, int fontColor) {
	sf::Text text;
	text.setFont(fonts[fontName]); 
	text.setString(content);
	text.setCharacterSize(fontSize);
	text.setFillColor(sf::Color(fontColor));
	return text;
}

/**
 * @brief Kicks off and holds the main game loop.
 * 
 * @return true when window is closed
 * @return false on fatal error
 */
bool Game::beginGameLoop() {
    sf::RenderWindow window(sf::VideoMode(config.resolution.width, config.resolution.height), "game");

	sf::Text levelText = formatText(level, "gohufont-11.bdf", 11, 0x306230ff);
	
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(textures["game-spritesheet.png"]);


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window.close();
			}
			if(event.type == sf::Event::Resized) {
				camera.getLetterboxView( event.size.width, event.size.height );
			}
		}
		window.clear();
		window.setView(camera.getView());
		window.draw(backgroundSprite);
		window.draw(levelText);
		
		window.display();
	}
    return true;
}