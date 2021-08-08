#pragma once
#include "Map.h"
#include "Cursor.h"
#include "Unit.h"
#include <queue>

enum DIRECTION { UP, RIGHT, DOWN, LEFT };


class MapController {
	private:
		Map* current_map;
		Cursor* cursor;
		Unit* allies;
		Unit* enemies;
		int turn;
		void fillAdjacent(int** ret, int x, int y, int width, int height, queue<int>& q);
		int convertTerrain(TERRAIN t);
	public:
		void moveCursor(DIRECTION direction);
		Map* getMap();
		Cursor* getCursor();
		int** getMovableSquare(unsigned int move);
		MapController();
		~MapController();
};