#include "map_tile_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>


MapTileHandler::MapTileHandler()
{
	mapTiles.reserve(GameConstants::NUMBER_TILES);
	loadMap("../Assets/maps/map1.txt");
	loadTileImages();
}

void MapTileHandler::loadTileImages()
{
	loadTileImage("../Assets/tiles/Grass.png", "Grass", false);
	loadTileImage("../Assets/tiles/Tree1.png", "Tree1", true);
	loadTileImage("../Assets/tiles/Tree2.png", "Tree2", true);
	loadTileImage("../Assets/tiles/Tree3.png", "Tree3", true);
	loadTileImage("../Assets/tiles/Shrub.png", "Shrub", true);
	loadTileImage("../Assets/tiles/Underbrush.png", "Underbrush", false);
	loadTileImage("../Assets/tiles/Shrub_Underbrush.png", "ShrubUnderbrush", true);
	loadTileImage("../Assets/tiles/OrangeFlower.png", "OrangeFlower", false);
	loadTileImage("../Assets/tiles/Tree1_Flies1.png", "TreeFlies1", true);
	loadTileImage("../Assets/tiles/Tree1_Beehive1.png", "TreeBeehive1", true);
	loadTileImage("../Assets/tiles/Tree1_Woodpecker1.png", "TreeWoodpecker1", true);
}

void MapTileHandler::drawAll(sf::RenderWindow* window)
{
	for (int r = 0; r < GameConstants::NUMBER_WORLD_ROWS; r++)
	{
		for (int c = 0; c < GameConstants::NUMBER_WORLD_COLS; c++)
		{
			int tileNumber = mapTileNumbers[r][c];
			MapTile tile = mapTiles[tileNumber];
			sf::Vector2<float> position(r * GameConstants::NUMBER_WORLD_ROWS, c * GameConstants::NUMBER_WORLD_COLS);
			tile.sprite.setPosition(position);
			window->draw(tile.sprite);
		}
	}
}

void MapTileHandler::loadTileImage(const std::string& imageFileName, const std::string& name, bool isSolid)
{
	MapTile tile(imageFileName, name, isSolid);
	tile.sprite.setScale({ 0.1f, 0.1f });
	mapTiles.emplace_back(tile);
	mapTiles.back().sprite.setTexture(mapTiles.back().texture);
}

void MapTileHandler::loadMap(const std::string& fileName) {
	std::ifstream mapFile;
	mapFile.open(fileName);

	if (mapFile.is_open())
	{
		std::string currLine;

		int row = 0;
		int col = 0;
		while (std::getline(mapFile, currLine))
		{
			std::istringstream iss(currLine);
			std::string currNumber;
			while (iss >> currNumber)
			{
				mapTileNumbers[row][col] = std::stoi(currNumber);
				col++;
			}
			col = 0;
			row++;
		}
	}
}