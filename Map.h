#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Map {
	private:
		string map_name;
		unsigned width;
		unsigned height;
		enum TERRAIN {PLAIN, FOREST, THICKET, FLOOR, PILLAR, MOUNTAIN, PEAK, GATE, THRONE, SEA, DESERT};
		TERRAIN** map_terrain;
	public:
		string getMapName();
		unsigned getWidth();
		unsigned getHeight();
		Map();
		
};
