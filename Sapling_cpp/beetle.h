#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"

class Beetle {
public:
	Beetle(const std::string& spritePath1, const std::string& spritePath2);

	void switchTexture();
	void changeDirection(const Direction newDirection);

	void draw(sf::RenderWindow* window);
	void update();

	Direction direction;
	sf::Texture* currTexture;
	sf::Texture texture1;
	sf::Texture texture2;

	sf::Sprite currSprite;
	int speed;
	float x, y;


private:
	int currTextureNumber;
	float rotationDegrees;
};