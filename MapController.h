#pragma once
#include "Map.h"
#include "Cursor.h"

class MapController {
	private:
		enum DIRECTION {UP, RIGHT, DOWN, LEFT};
		Map& current_map;
		Cursor& cursor;
	public:
		void moveCursor(DIRECTION direction);

};