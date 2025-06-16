#include "beetle.h"

Beetle::Beetle(std::string spritePath1, std::string spritePath2) {
	try {
		texture1 = sf::Texture("../Assets/Beetle/BeetleDown1.png");
		texture2 = sf::Texture("../Assets/Beetle/BeetleDown2.png");
		currTexture = texture1;
	}
	catch (sf::Exception e) {}

	currTextureNumber = 1;
	currSprite = sf::Sprite( currTexture );
	direction = DOWN;
}

void Beetle::changeDirection(Direction newDirection) {
	direction = newDirection;
}

void Beetle::switchTexture() {
	if (currTextureNumber == 1) {
		currTexture = texture2;
		currTextureNumber = 2;
	}
	else {
		currTexture = texture1;
		currTextureNumber = 1;
	}
}