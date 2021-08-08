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
			if (line_count == 0) {
				map_name = line;
			} else if (line_count == 1) {
				int space = 0;
				while (line[space] != ' ') {
					space++;
				}
				string s1 = line.substr(0, space);
				string s2 = line.substr(space + 1);
				height = stoi(s1);
				width = stoi(s2);
				map_terrain = new TERRAIN* [height];
				for (int i = 0; i < height; i++) {
					map_terrain[i] = new TERRAIN[width];
				}
			} else {
				int cur_line = line_count - 2;
				char* c_arr = new char[line.size() + 1]; //We need a char pointer for strtok
				for (int i = 0; i < line.size(); i++) {
					c_arr[i] = line.at(i);
				}
				c_arr[line.size()] = ' ';
				rsize_t strmax = line.size();
				const char* delim = " ";
				char* next_token;
				char* token = strtok_s(c_arr, delim, &next_token);
				for (int count = 0; count < width; count++) {
					map_terrain[cur_line][count] = convertNumtoTerrain(stoi(token));
					token = strtok_s(NULL, delim, &next_token);
				}
			}
			line_count++;
		}
		width = 10;
		height = 10;
		map_terrain = NULL;
		map_file.close();
	} else {
		cout << "dumy" << endl;
		map_name = "???";
		width = 10;
		height = 10;
		map_terrain = NULL;
	}

}

TERRAIN Map::convertNumtoTerrain(int num) {
	if (num == 244) {
		return SEA;
	}
	return PLAIN;
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