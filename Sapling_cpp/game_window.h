#pragma once
#include <SFML/Graphics.hpp>
#include "beetle.h"
#include "game_constants.h"
#include "map_tile_handler.h"

class GameWindow {
public:
	GameWindow();
	void run();
	void update();
	void draw();

private:
	sf::RenderWindow window;
	Beetle beetle;
	sf::Clock clock;
	MapTileHandler mapTileHandler;
};