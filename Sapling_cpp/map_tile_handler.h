#pragma once
#include <string>
#include "game_constants.h"

class MapTileHandler
{
public:
	int mapTileNumbers[GameConstants::NUMBER_WORLD_ROWS][GameConstants::NUMBER_WORLD_COLS];
	void loadMap(const std::string& fileName);
};

