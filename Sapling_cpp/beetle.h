#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"

class Beetle {
public:
	Beetle();
	Beetle(std::string spritePath1, std::string spritePath2);
	sf::Sprite currSprite;

	void switchTexture();
	void changeDirection(Direction newDirection);

private:
	Direction direction;
	sf::Texture texture1;
	sf::Texture texture2;
	int currTextureNumber;
	sf::Texture currTexture;

};