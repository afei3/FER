#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "Cursor.h"


using namespace std;

class Map {
	private:
		string map_name;
		Cursor cursor;
		unsigned width;
		unsigned height;
	public:
		string getMapName();
		int getCursorX();
		int getCursorY();
};
