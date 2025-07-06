#include "map_tile.h"


MapTile(sf::Texture texture, sf::Sprite sprite, const std::string& name, bool isSolid) : name(name), isSolid(isSolid)
{
	this.texture = texture;
	this.sprite = sprite;
}
