/**
 * @file main.cpp
 * @author Cody Potter (me@codypotter.com)
 * @brief The entry point for executing the game.
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

/**
 * @brief Creates a game object.
 * 
 * @return int 0 when done.
 */
int main(void) {
	Config config = {
		{			/** Resolution */
			160,	/** width */
			144		/** height */
		}
	};

	Game game = Game(config);

	return 0;
}
