#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class MapTile {
public:
	sf::Texture texture;
	sf::Sprite sprite;
	bool isSolid;
	std::string name;

	MapTile(const std::string& fileName, const std::string& name, bool isSolid);
	void draw();
};