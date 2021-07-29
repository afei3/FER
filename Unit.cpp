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