#include "Map.h"

string Map::getMapName() {
	return map_name;
}

unsigned Map::getHeight() {
	return height;
}

unsigned Map::getWidth() {
	return width;
}

Map::Map() {
	map_name = "???";
	width = 100;
	height = 100;
}

Map::Map(TERRAIN** map, unsigned u_width, unsigned u_height) {
	map_name = "???";
	width = u_width;
	height = u_height;
	map_terrain = new TERRAIN*[width];
	for (unsigned i = 0; i < width; i++) {
		map_terrain[i] = new TERRAIN[height];
	}
	for (unsigned i = 0; i < width; i++) {
		for (unsigned j = 0; j < height; j++) {
			map_terrain[i][j] = map[i][j];
		}
	}
}

Map::Map(string text_file) {
	string line;
	ifstream map_file(text_file);
	if (map_file.is_open()) {
		int line_count = 0;
		while (getline(map_file, line)) {
			cout << line << endl;
			line_count++;
		}
		map_name = "???";
		width = 10;
		height = 10;
		map_terrain = NULL;
		map_file.close();
	} else {
		cout << "dummy" << endl;
		map_name = "???";
		width = 10;
		height = 10;
		map_terrain = NULL;
	}

}

TERRAIN** Map::getTerrain() {
	return map_terrain;
}

Map::~Map() {
	for (unsigned i = 0; i < width; i++) {
		delete[] map_terrain[i];
	}

	delete[] map_terrain;
	width = 0;
	height = 0;
}