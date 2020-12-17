#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "MapController.h"


class ImageProcessor {
	private:
		MapController* MapController;
		SDL_Window* gWindow = NULL;
		SDL_Surface* gScreenSurface = NULL;
		SDL_Surface* gPNGSurface = NULL;
		class LTexture
		{
		public:
			//Initializes variables
			LTexture();

			//Deallocates memory
			~LTexture();

			//Loads image at specified path
			bool loadFromFile(std::string path);

			bool loadFromFile(std::string path, SDL_Renderer* renderer);

			//Deallocates texture
			void free();

			//Set color modulation
			void setColor(Uint8 red, Uint8 green, Uint8 blue);

			//Set blending
			void setBlendMode(SDL_BlendMode blending);

			//Set alpha modulation
			void setAlpha(Uint8 alpha);

			//Renders texture at given point
			void render(int x, int y, SDL_Rect* clip = NULL);

			//Gets image dimensions
			int getWidth();
			int getHeight();

		private:
			//The actual hardware texture
			SDL_Texture* mTexture;

			SDL_Renderer* gRenderer = NULL;

			//Image dimensions
			int mWidth;
			int mHeight;
		};

		const int WALKING_ANIMATION_FRAMES = 4;
		const int SCREEN_WIDTH = 640;
		const int SCREEN_HEIGHT = 480;
		SDL_Rect gSpriteClips[4];
		LTexture gSpriteSheetTexture;
		SDL_Renderer* gRenderer = NULL;


	public:
		bool init();
		bool loadMedia();
		void close();
		SDL_Surface* loadSurface(std::string path);
		void run();


};