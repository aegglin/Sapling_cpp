#include "map_tile.h"

MapTile::MapTile() : isSolid{ false }, hasSound{ false } {}
MapTile::MapTile(bool isSolid, bool hasSound) : isSolid{ isSolid }, hasSound{ hasSound } {}