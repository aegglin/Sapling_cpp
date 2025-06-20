
#include <SFML/Graphics.hpp>
#include "game_window.h"
#include "direction.h"

GameWindow::GameWindow() : 
	window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "Sapling"),
	beetle("../Assets/Beetle/BeetleDown1.png", "../Assets/Beetle/BeetleDown2.png") {

}

void GameWindow::run() {
	while (window.isOpen())
	{

		// runs as long as the window is open
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		// clears the window with black so previous frame drawing is gone
		window.clear(sf::Color::White);

		// draws
		sf::Sprite currSprite(beetle.currTexture);

		window.draw(currSprite);

		// copy from buffer to the window
		window.display();
	}
}