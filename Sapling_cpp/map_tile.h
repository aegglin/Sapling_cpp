#pragma once
#include <SFML/Graphics.hpp>

class MapTile {
public:
	bool isSolid;
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;

	MapTile(sf::Texture texture, sf::Sprite sprite, const std::string& name, bool isSolid);
};