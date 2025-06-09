#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>

void renderingThread(sf::RenderWindow* window)
{
	window->setActive(true);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window->isOpen())
	{
		window->clear(sf::Color::Black); // Calling clear before drawing anything is mandatory
		window->draw(shape);
		window->display(); //takes what was drawn on the last call to display and displays it
	}
}


int main()
{
	// create window in main thread
	sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "SFML works!");


	// deactivate its OpenGL context
	window.setActive(false);

	// launch the rendering thread
	std::thread thread(&renderingThread, &window);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}
	}
	thread.join();
	//std::cin.get();
}