#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include "beetle.h"

int main()
{

	Beetle beetle{ "../Assets/Beetle/BeetleDown1.png", "../Assets/Beetle/BeetleDown2.png" };

	// creates the window
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Sapling");
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
		//window.draw(beetle.currSprite);
		
		// copy from buffer to the window
		window.display();
	}
}