#pragma once
#include "Map.h"
#include "Cursor.h"
#include "Unit.h"

enum DIRECTION { UP, RIGHT, DOWN, LEFT };


class MapController {
	private:
		Map* current_map;
		Cursor* cursor;
		Unit* allies;
		Unit* enemies;
		int turn;
	public:
		void moveCursor(DIRECTION direction);
		Map* getMap();
		Cursor* getCursor();
		MapController();

};