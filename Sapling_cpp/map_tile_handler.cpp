#include "map_tile_handler.h"
#include <fstream>
#include <iostream>
#include <format>

void MapTileHandler::loadMap(const std::string& fileName) {
	std::ifstream mapFile;
	mapFile.open(fileName);

	if (mapFile.is_open())
	{
		std::string currNumber;
		int row = 0;
		int col = 0;
		while (std::getline(mapFile, currNumber, ' '))
		{
			std::cout << "CurrNumber: " << currNumber << std::endl;
			if (col < GameConstants::NUMBER_WORLD_COLS)
			{
				std::cout << "Row is: " << row << " col is: " << col << " Number is: " << currNumber << std::endl;
				mapTileNumbers[row][col] = std::stoi(currNumber);
				col++;
			}
			else {
				col = 0;
				row++;
			}
		}
	}
}