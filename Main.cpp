/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "ImageProcessor.h"
#include "Map.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* args[])
{

	Map* m = new Map("test_map.map");

	free(m);

	ImageProcessor i = ImageProcessor();

	i.run();

	return 0;
}