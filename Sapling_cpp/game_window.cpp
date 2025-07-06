
#include <SFML/Graphics.hpp>
#include "direction.h"
#include "game_window.h"

GameWindow::GameWindow() : 
	window(sf::VideoMode({ GameConstants::SCREEN_WIDTH, GameConstants::SCREEN_HEIGHT }), "Sapling"),
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
{}

void GameWindow::update() {
	beetle.update();
}

void GameWindow::draw() {
	beetle.draw(&window);
}

void GameWindow::run() {
	window.setFramerateLimit(60);

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
		update();
		// clears the window with black so previous frame drawing is gone
		window.clear(sf::Color::White);
		draw();
		// copy from buffer to the window
		window.display();
	}
}