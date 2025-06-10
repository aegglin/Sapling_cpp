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
	sf::RenderWindow window(sf::VideoMode({ 600, 600 }), "SFML works!", sf::Style::Close, sf::State::Windowed);


	// deactivate its OpenGL context
	window.setActive(false);
	// Be sure application refresh rate is synchronized with vertical freq of monitor to avoid tearing
	//window.setVerticalSyncEnabled(true);

	window.setFramerateLimit(60); // set the frame limit explicitly

	// launch the rendering thread
	std::thread thread(&renderingThread, &window);

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
					window.close();
			}
		}
	}
	thread.join();
	//std::cin.get();
}