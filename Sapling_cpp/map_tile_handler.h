#pragma once
#include <string>
#include "game_constants.h"
#include "map_tile.h"

class MapTileHandler
{
public:
	MapTileHandler();
	int mapTileNumbers[GameConstants::NUMBER_WORLD_ROWS][GameConstants::NUMBER_WORLD_COLS];
	void loadMap(const std::string& fileName);
	void loadTileImages();
	void drawAll(sf::RenderWindow* window);

private:
	std::vector<MapTile*> mapTiles;
	void loadTileImage(const std::string& imageFileName, const std::string& name, bool isSolid);
};

