
#include <SFML/Graphics.hpp>
#include "game_window.h"
#include "direction.h"

GameWindow::GameWindow() : 
	window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "Sapling"),
	beetle(
		"../Assets/beetle/BeetleUp1.png",
		"../Assets/beetle/BeetleUp2.png",
		"../Assets/beetle/BeetleDown1.png",
		"../Assets/beetle/BeetleDown2.png",
		"../Assets/beetle/BeetleRight1.png", 
		"../Assets/beetle/BeetleRight2.png",
		"../Assets/beetle/BeetleLeft1.png",
		"../Assets/beetle/BeetleLeft2.png"
	)
{
}

void GameWindow::update() {
	beetle.update();
}

void GameWindow::draw() {
	beetle.draw(&window);
}

void GameWindow::run() {
	window.setFramerateLimit(60);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time delta;

	while (window.isOpen())
	{
		delta = clock.restart();
		timeSinceLastUpdate += delta;

		// runs as long as the window is open
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}
		
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			// clears the window with black so previous frame drawing is gone
			window.clear(sf::Color::White);

			update();
			draw();
		}

		// copy from buffer to the window
		window.display();
	}
}