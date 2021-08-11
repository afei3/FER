#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

enum TERRAIN { PLAIN, FOREST, THICKET, FLOOR, PILLAR, MOUNTAIN, PEAK, GATE, THRONE, SEA, DESERT };


class Map {

	//When working with the graph, height is first, width is second
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
		TERRAIN convertNumtoTerrain(int num);
		TERRAIN** getTerrain();
		Map(string text_file);
		~Map();
		
};
