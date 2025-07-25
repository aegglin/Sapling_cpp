#pragma once
namespace GameConstants {
	static constexpr int RAW_PIXEL_TILE_SIZE = 16;
	static constexpr int SCALE = 3;
	static constexpr int MAX_SCREEN_COL = 16;
	static constexpr int MAX_SCREEN_ROW = 12;
	static constexpr int FPS = 60;
	static constexpr int TILE_SIZE = RAW_PIXEL_TILE_SIZE * SCALE;
	static constexpr int SCREEN_WIDTH = TILE_SIZE * MAX_SCREEN_COL;
	static constexpr int SCREEN_HEIGHT = TILE_SIZE * MAX_SCREEN_ROW;
	static constexpr int NUMBER_WORLD_ROWS = 50;
	static constexpr int NUMBER_WORLD_COLS = 50;
	static constexpr int WORLD_WIDTH = TILE_SIZE * NUMBER_WORLD_ROWS;
	static constexpr int WORLD_HEIGHT = TILE_SIZE * NUMBER_WORLD_COLS;
	static constexpr int NUMBER_TILES = 11;
};