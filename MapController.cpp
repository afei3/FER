#include "MapController.h"

void MapController::moveCursor(DIRECTION direction) {
	if (direction == UP) {
		if (cursor->getY() > 0) {
			cursor->moveUp();
		}
	} else if (direction == RIGHT) {
		if (cursor->getX() < current_map->getWidth()) {
			cursor->moveRight();
		}
	} else if (direction == DOWN) {
		if (cursor->getY() < current_map->getHeight()) {
			cursor->moveDown();
		}
	} else if (direction == LEFT) {
		if (cursor->getX() > 0) {
			cursor->moveLeft();
		}
	}
}