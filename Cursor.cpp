#include "Cursor.h"

unsigned Cursor::getX() {
	return x;
};

unsigned Cursor::getY() {
	return y;
}

void Cursor::moveDown() {
	y += 1;
}

void Cursor::moveUp() {
	y -= 1;
}

void Cursor::moveLeft() {
	x += 1;
}

void Cursor::moveRight() {
	x -= 1;
}

Cursor::Cursor() {
	x = 0;
	y = 0;
}