#include "beetle.h"

Beetle::Beetle(const std::string& spritePath1, const std::string& spritePath2) :
		currTextureNumber(1),
		direction(DOWN),
		speed(4),
		x(20), y(20),
		texture1(spritePath1),
		texture2(spritePath2),
		currTexture(&texture1),
		currSprite(texture1) {}

void Beetle::changeDirection(const Direction newDirection) {
	direction = newDirection;
}

void Beetle::update() {
	float degrees = 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		changeDirection(UP);
		degrees = 180.0;
		y -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		changeDirection(DOWN);
		y += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		changeDirection(RIGHT);
		degrees = 90.0;
		x += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		changeDirection(LEFT);
		degrees = 270.0;
		x -= speed;
	}
	currSprite.rotate(sf::degrees(degrees));
}

void Beetle::draw(sf::RenderWindow* window) {
	window->draw(currSprite);
}

void Beetle::switchTexture() {
	if (currTextureNumber == 1) {
		currTexture = &texture2;
		currTextureNumber = 2;
	}
	else {
		currTexture = &texture1;
		currTextureNumber = 1;
	}
}

