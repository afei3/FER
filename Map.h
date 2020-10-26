#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Map {
	private:
		string map_name;
		unsigned width;
		unsigned height;
	public:
		string getMapName();
		unsigned getWidth();
		unsigned getHeight();
		
};
