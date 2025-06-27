#pragma once
#include <SFML/Graphics.hpp>
#include "direction.h"

class Beetle {
public:
	Beetle(
		const std::string& upPath1,
		const std::string& upPath2,
		const std::string& downPath1,
		const std::string& downPath2,
		const std::string& rightPath1,
		const std::string& rightPath2,
		const std::string& leftPath1,
		const std::string& leftPath2
	);

	void changeDirection(const Direction newDirection);

	void draw(sf::RenderWindow* window);
	void update();

	Direction direction;
	sf::Texture upTexture1;
	sf::Texture upTexture2;
	sf::Texture downTexture1;
	sf::Texture downTexture2;
	sf::Texture rightTexture1;
	sf::Texture rightTexture2;
	sf::Texture leftTexture1;
	sf::Texture leftTexture2;
	sf::Sprite upSprite1;
	sf::Sprite upSprite2;
	sf::Sprite downSprite1;
	sf::Sprite downSprite2;
	sf::Sprite rightSprite1;
	sf::Sprite rightSprite2;
	sf::Sprite leftSprite1;
	sf::Sprite leftSprite2;

	sf::Texture* currTexture;
	sf::Sprite* currSprite;

	float x, y, speed;

private:
	int currSpriteNumber;
	int spriteUpdateCount;

	static constexpr int SPRITE_SWITCH_FRAME_THRESHOLD = 12;
};