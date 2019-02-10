#include<SFML/Graphics.hpp>

class Camera {
public:
    sf::View getView();
    sf::View getLetterboxView(int newWindowWidth, int newWindowHeight);
    Camera(int gameResWidth, int gameResHeight);
    Camera();
private:
    sf::View view;
    int windowWidth;
    int windowHeight;
    float aspectRatio;
};