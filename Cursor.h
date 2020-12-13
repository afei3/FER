#pragma once

#include <string>

using namespace std;

class Cursor {
	private:
		unsigned x;
		unsigned y;
	public:
		unsigned getX();
		unsigned getY();
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
};