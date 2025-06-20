#include "beetle.h"

Beetle::Beetle(const std::string& spritePath1, const std::string& spritePath2) {
	try {
		texture1 = sf::Texture("../Assets/Beetle/BeetleDown1.png");
		texture2 = sf::Texture("../Assets/Beetle/BeetleDown2.png");
	}
	catch (sf::Exception e) {}

	currTexture = texture1;

	currTextureNumber = 1;
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

