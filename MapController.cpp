#include "MapController.h"
#include <queue>

using namespace std;

void MapController::moveCursor(DIRECTION direction) {
	if (direction == UP) {
		if (cursor->getY() > 0) {
			cursor->moveUp();
		}
	} else if (direction == RIGHT) {
		if (cursor->getX() < current_map->getWidth() - 1) {
			cursor->moveRight();
		}
	} else if (direction == DOWN) {
		if (cursor->getY() < current_map->getHeight() - 1) {
			cursor->moveDown();
		}
	} else if (direction == LEFT) {
		if (cursor->getX() > 0) {
			cursor->moveLeft();
		}
	}
}

Map* MapController::getMap() {
	return current_map;
}

Cursor* MapController::getCursor() {
	return cursor;
}

MapController::MapController() {
	current_map = new Map();
	cursor = new Cursor();
	allies = new Unit[10];
	enemies = new Unit[10];
	turn = 0;
}

MapController::MapController(string file) {
	current_map = new Map(file);
	cursor = new Cursor();
	allies = new Unit[10];
	enemies = new Unit[10];
	turn = 0;
}

int MapController::convertTerrain(TERRAIN t) {
	if (t == PLAIN) {
		return 1;
	}
	if (t == FOREST) {
		return 2;
	}
	if (t == THICKET) {
		return 2;
	}
	if (t == FLOOR) {
		return 1;
	}
	if (t == PILLAR) {
		return 2;
	}
	if (t == MOUNTAIN) {
		return 4;
	}
	if (t == PEAK) {
		return 99;
	}
	if (t == GATE) {
		return 2;
	}
	if (t == THRONE) {
		return 2;
	}
	if (t == SEA) {
		return 99;
	}
	if (t == DESERT) {
		return 3;
	}
	return 99;
}

void MapController::fillAdjacent(int** ret, int x, int y, int width, int height, queue<int>& q) {
	//Left
	if (x != 0) {
		if (ret[x - 1][y] > ret[x][y] + convertTerrain(current_map->getTerrain()[x - 1][y])) {
			ret[x - 1][y] = ret[x][y] + convertTerrain(current_map->getTerrain()[x - 1][y]);
			q.push(x - 1);
			q.push(y);
		}
	}

	//Right
	if (x < width - 1) {
		if (ret[x + 1][y] > ret[x][y] + convertTerrain(current_map->getTerrain()[x + 1][y])) {
			ret[x + 1][y] = ret[x][y] + convertTerrain(current_map->getTerrain()[x + 1][y]);
			q.push(x + 1);
			q.push(y);
		}
	}

	//Up
	if (y < height - 1) {
		if (ret[x][y + 1] > ret[x][y] + convertTerrain(current_map->getTerrain()[x][y + 1])) {
			ret[x][y + 1] = ret[x][y] + convertTerrain(current_map->getTerrain()[x][y + 1]);
			q.push(x);
			q.push(y + 1);
		}
	}

	//Down
	if (y != 0) {
		if (ret[x][y - 1] > ret[x][y] + convertTerrain(current_map->getTerrain()[x][y - 1])) {
			ret[x][y - 1] = ret[x][y] + convertTerrain(current_map->getTerrain()[x][y - 1]);
			q.push(x);
			q.push(y - 1);
		}
	}
}

int** MapController::getMovableSquare(unsigned int move) {
	int** ret;

	ret = new int* [current_map->getWidth()];
	for (unsigned int i = 0; i < current_map->getWidth(); i++) {
		ret[i] = new int[current_map->getHeight()];
		for (unsigned int j = 0; j < current_map->getHeight(); j++) {
			ret[i][j] = 99;
		}
	}

	ret[cursor->getX()][cursor->getY()] = 0;
	queue<int> q;
	q.push(cursor->getX());
	q.push(cursor->getY());
	while (!q.empty()) {
		int n_x = q.front();
		q.pop();
		int n_y = q.front();
		q.pop();
		fillAdjacent(ret, n_x, n_y, current_map->getWidth(), current_map->getHeight(), q);
	}
	return ret;
}

MapController::~MapController() {
	free(current_map);
	free(cursor);
	delete[] allies;
	delete[] enemies;
}