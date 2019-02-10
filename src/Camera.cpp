/**
 * @file Camera.cpp
 * @author Cody Potter (me@codypotter.com)
 * @brief The main game camera.
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include"Camera.h"

/**
 * @brief Construct a new Camera:: Camera object
 * 
 */
Camera::Camera() {
    
}

/**
 * @brief Construct a new Camera:: Camera object
 * 
 * @param gameResWidth is the horizontal game resolution
 * @param gameResHeight is the vertical game resolution
 */
Camera::Camera(int gameResWidth, int gameResHeight) {
    view.setSize( gameResWidth, gameResHeight);
	view.setCenter( view.getSize().x / 2, view.getSize().y / 2 );
	getLetterboxView(gameResWidth, gameResHeight);

    aspectRatio = view.getSize().x / (float) view.getSize().y;
}

/**
 * @brief Getter for the camera view.
 * 
 * @return sf::View 
 */
sf::View Camera::getView() {
    return view;
}

/**
 * @brief Maintains the original aspect ratio on scale.
 * 
 * Compares the aspect ratio of the window to the aspect ratio of the view,
 * and sets the view's viewport accordingly in order to achieve a letterbox effect.
 *
 * @param newWindowWidth The most updated window width (typically a result of a resize event).
 * @param newWindowHeight The most updated window height (typically a result of a resize event).
 * @return sf::View A new view (with a new viewport set) is returned. 
 */
sf::View Camera::getLetterboxView(int newWindowWidth, int newWindowHeight) {

    float windowRatio = newWindowWidth / (float) newWindowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    if (!(windowRatio < viewRatio)) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    } else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}

