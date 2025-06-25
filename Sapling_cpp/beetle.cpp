#include "beetle.h"
#include <iostream>

Beetle::Beetle(const std::string& spritePath1, const std::string& spritePath2) :
		currTextureNumber(1),
		rotationDegrees(0),
		direction(DOWN),
		speed(4),
		x(50.0f), y(50.0f),
		texture1(spritePath1),
		texture2(spritePath2),
		currTexture(&texture1),
		currSprite(texture1) {
	currSprite.setScale({ 0.1f, 0.1f });
	currSprite.setPosition({ x, y });
}

void Beetle::changeDirection(const Direction newDirection) {
	direction = newDirection;
}

void Beetle::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		changeDirection(UP);
		rotationDegrees = 180.0f;
		//y -= speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		changeDirection(DOWN);
		rotationDegrees = 0.0f;
		//y += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		changeDirection(RIGHT);
		rotationDegrees = 90.0f;
		//x += speed;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		changeDirection(LEFT);
		rotationDegrees = 270.0f;
		//x -= speed;
	}
	currSprite.setRotation(sf::degrees(rotationDegrees));
	//currSprite.setRotation(sf::degrees(40.0f));
	//currSprite.move({x, y});
}

void Beetle::draw(sf::RenderWindow* window) {
	window->draw(currSprite);
	std::cout << "drew" << std::endl;
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