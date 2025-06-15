#pragma once
class MapTile {
public:
	bool isSolid;
	bool hasSound;
	
	MapTile();
	MapTile(bool isSolid, bool hasSound);
};