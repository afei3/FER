#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

enum TERRAIN { PLAIN, FOREST, THICKET, FLOOR, PILLAR, MOUNTAIN, PEAK, GATE, THRONE, SEA, DESERT };


class Map {
	private:
		string map_name;
		unsigned width;
		unsigned height;
		TERRAIN** map_terrain;
	public:
		string getMapName();
		unsigned getWidth();
		unsigned getHeight();
		Map();
		Map(TERRAIN** map, unsigned u_width, unsigned u_height);
		TERRAIN** getTerrain();
		~Map();
		
};
