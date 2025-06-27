
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
	//window.setFramerateLimit(60);
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

		update();
		draw();

		// copy from buffer to the window
		window.display();
	}
}