#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"

class Beetle {
public:
	Beetle(const std::string& spritePath1, const std::string& spritePath2);

	void switchTexture();
	void changeDirection(Direction newDirection);

	void setSprite();

	void draw(sf::Window* window);
	void update();

	sf::Texture currTexture;

private:
	Direction direction;
	sf::Texture texture1;
	sf::Texture texture2;
	int currTextureNumber;
};