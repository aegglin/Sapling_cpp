
#include <SFML/Graphics.hpp>
#include "game_window.h"

GameWindow::GameWindow() {
	sf::RenderWindow window(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "Sapling");
}

void GameWindow::run() {
	
}