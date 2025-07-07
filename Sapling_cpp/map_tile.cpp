#include "map_tile.h"


MapTile::MapTile(
		const std::string& fileName,
		const std::string& name,
		bool isSolid
	) : 
		texture(fileName), sprite(texture), name(name), isSolid(isSolid)
{}