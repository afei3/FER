#pragma once
#include <string>
#include "Item.h"

using namespace std;

enum CLASS {GAMER, NOT_GAMER};

class Unit {
	private:
		string name;
		int hp;
		int max_hp;
		int move;
		int level;
		int xp;
		int stats[8];
		int stat_growths[8];
		int max_stats[8];
		CLASS c;
		Item items[5];
		

	public:
		void levelUp();
		Unit();
};