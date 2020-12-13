#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "MapController.h"
#include "LTexture.h"


class ImageProcessor {
	private:
		MapController* MapController;
		SDL_Window* gWindow = NULL;
		SDL_Surface* gScreenSurface = NULL;
		SDL_Surface* gPNGSurface = NULL;
		LTexture* gSprite = NULL;

	public:
		bool init();
		bool loadMedia();
		void close();
		SDL_Surface* loadSurface(std::string path);
		void run();


};