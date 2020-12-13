/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "ImageProcessor.h"

int main(int argc, char* args[])
{

	ImageProcessor i = ImageProcessor();

	i.run();

	return 0;
}