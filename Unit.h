#pragma once
#include <string>

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
		double stat_growths[8];
		int max_stats[8];
		CLASS c;

	public:
		void levelUp();
};