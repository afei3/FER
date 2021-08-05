#include "Unit.h"
#include <stdlib.h>

void Unit::levelUp() {
	while (xp >= 100) {
		level++;
		for (int i = 0; i < 8; i++) {
			int r = rand() % 100 + 1;
			if (stats[i] < max_stats[i] && r < stat_growths[i]) {
				stats[i]++;
			}
		}
		xp -= 100;
	}
}

Unit::Unit() {
	name = "";
	hp = 0;
	max_hp = 0;
	move = 0;
	level = 0;
	xp = 0;
	for (int i = 0; i < 8; i++) {
		stats[i] = 0;
		stat_growths[i] = 0;
		max_stats[i] = 0;
	}
}