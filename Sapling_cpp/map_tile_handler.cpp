#include "map_tile_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>


MapTileHandler::MapTileHandler() : currTileNumber(0)
{
	loadTileImages();
	loadMap("../Assets/maps/map1.txt");
}

void MapTileHandler::loadTileImages()
{
	loadTileImage("../Assets/Grass.png", "Grass", false);
	loadTileImage("../Assets/Tree1.png", "Tree1", true);
	loadTileImage("../Assets/Tree2.png", "Tree2", true);
	loadTileImage("../Assets/Tree3.png", "Tree3", true);
	loadTileImage("../Assets/Shrub.png", "Shrub", true);
	loadTileImage("../Assets/Underbrush.png", "Underbrush", false);
	loadTileImage("../Assets/Shrub_Underbrush.png", "ShrubUnderbrush", true);
	loadTileImage("../Assets/OrangeFlower.png", "OrangeFlower", false);
	loadTileImage("../Assets/Tree1_Flies1.png", "TreeFlies1", true);
	loadTileImage("../Assets/Tree1_Beehive1.png", "TreeBeehive1", true);
	loadTileImage("../AssetsTree1_Woodpecker1.png", "TreeWoodpecker1", true);
}

void MapTileHandler::loadTileImage(const std::string& imageFileName, const std::string& name, bool isSolid)
{
	sf::Texture texture(imageFileName);
	sf::Sprite sprite(texture);

	MapTile tile(texture, sprite, name, isSolid);
	mapTiles[currTileNumber] = tile;
	currTileNumber++;
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