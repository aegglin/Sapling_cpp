#include "beetle.h"
#include <iostream>
#include "game_window.h"

Beetle::Beetle(
			const std::string& upPath1,
			const std::string& upPath2,
			const std::string& downPath1,
			const std::string& downPath2,
			const std::string& rightPath1,
			const std::string& rightPath2,
			const std::string& leftPath1,
			const std::string& leftPath2
		) :
			currSpriteNumber(1),
			spriteUpdateCount(0),
			direction(DOWN),
			speed(3.00f),
			x(50.0f), y(50.0f),
			upTexture1(upPath1),
			upTexture2(upPath2),
			downTexture1(downPath1),
			downTexture2(downPath2),
			rightTexture1(rightPath1),
			rightTexture2(rightPath2),
			leftTexture1(leftPath1),
			leftTexture2(leftPath2),
			upSprite1(upTexture1),
			upSprite2(upTexture2),
			downSprite1(downTexture1),
			downSprite2(downTexture2),
			rightSprite1(rightTexture1),
			rightSprite2(rightTexture2),
			leftSprite1(leftTexture1),
			leftSprite2(leftTexture2),
			currTexture(&downTexture1),
			currSprite(&downSprite1)
{
	upSprite1.setScale({ 0.1f, 0.1f });
	upSprite2.setScale({ 0.1f, 0.1f });
	downSprite1.setScale({ 0.1f, 0.1f });
	downSprite2.setScale({ 0.1f, 0.1f });
	rightSprite1.setScale({ 0.1f, 0.1f });
	rightSprite2.setScale({ 0.1f, 0.1f });
	leftSprite1.setScale({ 0.1f, 0.1f });
	leftSprite2.setScale({ 0.1f, 0.1f });

	currSprite->setPosition({ x, y });
}

void Beetle::changeDirection(const Direction newDirection) {
	direction = newDirection;
}

void Beetle::update() {
	
	// Only animate/move if a key is pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
				changeDirection(UP);
				y -= speed;
				if (y < 0) {
					y = 0;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
				changeDirection(DOWN);
				y += speed;
				if (y + GameConstants::TILE_SIZE > GameConstants::SCREEN_HEIGHT) {
					y = GameConstants::SCREEN_HEIGHT - GameConstants::TILE_SIZE;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
				changeDirection(RIGHT);
				x += speed;
				if (x + GameConstants::TILE_SIZE > GameConstants::SCREEN_WIDTH) {
					x = GameConstants::SCREEN_WIDTH - GameConstants::TILE_SIZE;
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
				changeDirection(LEFT);
				x -= speed;
				if (x < 0) {
					x = 0;
				}
			}
			currSprite->setPosition({ x, y });

			// counter for the number of frames that update has been called for with the current sprite
			spriteUpdateCount++;
			if (spriteUpdateCount > SPRITE_SWITCH_FRAME_THRESHOLD) {
				currSpriteNumber = currSpriteNumber == 1 ? 2 : 1;
				spriteUpdateCount = 0;
			}
	}
}

void Beetle::draw(sf::RenderWindow* window) {

	switch (direction) {
		case UP:
			if (currSpriteNumber == 1) {
				currSprite = &upSprite1;
			}
			else if (currSpriteNumber == 2) {
				currSprite = &upSprite2;
			}
			break;
		case DOWN:
			if (currSpriteNumber == 1) {
				currSprite = &downSprite1;
			}
			else if (currSpriteNumber == 2) {
				currSprite = &downSprite2;
			}
			break;
		case RIGHT:
			if (currSpriteNumber == 1) {
				currSprite = &rightSprite1;
			}
			else if (currSpriteNumber == 2) {
				currSprite = &rightSprite2;
			}
			break;
		case LEFT:
			if (currSpriteNumber == 1) {
				currSprite = &leftSprite1;
			}
			else if (currSpriteNumber == 2) {
				currSprite = &leftSprite2;
			}
			break;
	}
	currSprite->setPosition({ x, y });
	window->draw(*currSprite);
}