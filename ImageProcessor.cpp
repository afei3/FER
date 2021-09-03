#include "ImageProcessor.h"

bool ImageProcessor::init() {
	//Initialization flag
	bool success = true;
	map_controller = new MapController("test_map.map");

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool ImageProcessor::loadMedia() {
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("cursortotal1.png", gRenderer))
	{
		printf("Failed to load walking animation texture!\n");
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 32;
		gSpriteClips[0].h = 32;

		gSpriteClips[1].x = 32;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 32;
		gSpriteClips[1].h = 32;

		gSpriteClips[2].x = 64;
		gSpriteClips[2].y = 0;
		gSpriteClips[2].w = 32;
		gSpriteClips[2].h = 32;


		gSpriteClips[3].x = 32;
		gSpriteClips[3].y = 0;
		gSpriteClips[3].w = 32;
		gSpriteClips[3].h = 32;
	}

	if (!map_background.loadFromFile("test_map.png", gRenderer)) {
		printf("fmega\n");
		success = false;
	}

	return success;
}

void ImageProcessor::close() {
	//Free loaded image
	gSpriteSheetTexture.free();
	map_background.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* ImageProcessor::loadSurface(std::string path) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}

void ImageProcessor::run() {
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//Current animation frame
			int frame = 0;
			int** stuff = NULL;
			MODES cur_mode = CURSOR_MOVE;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.type == SDL_KEYDOWN) {
						switch (e.key.keysym.sym) {
							case SDLK_UP:
								map_controller->moveCursor(UP);
								break;
							case SDLK_DOWN:
								map_controller->moveCursor(DOWN);
								break;
							case SDLK_LEFT:
								map_controller->moveCursor(LEFT);
								break;
							case SDLK_RIGHT:
								map_controller->moveCursor(RIGHT);
								break;
							case SDLK_z:
								cout << map_controller->getMap()->getTerrain()[map_controller->getCursor()->getY()][map_controller->getCursor()->getX()] << endl;
								break;
							case SDLK_x: {
								if (cur_mode == CURSOR_MOVE) {
									stuff = map_controller->getMovableSquare(4);
									for (int i = 0; i < map_controller->getMap()->getHeight(); i++) {
										for (int j = 0; j < map_controller->getMap()->getWidth(); j++) {
											cout << stuff[i][j] << " ";
										}
										cout << endl;
									}
									cur_mode = CHARACTER_SELECTED;
								} else {
									for (int i = 0; i < map_controller->getMap()->getHeight(); i++) {
										delete[] stuff[i];
									}
									delete[] stuff;
									cur_mode = CURSOR_MOVE;
								}
							}
								break;
							default:
								cout << map_controller->getCursor()->getY() << " " << map_controller->getCursor()->getX() << endl;
								break;
						}
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render current frame
				SDL_Rect* currentClip = &gSpriteClips[frame / 4];
				map_background.render(0, 0);
				gSpriteSheetTexture.render(map_controller->getCursor()->getX() * DIST, map_controller->getCursor()->getY() * DIST, currentClip);
				if (cur_mode == CHARACTER_SELECTED) {
					colorSquares(stuff, 4);
				}

				//Update screen
				SDL_RenderPresent(gRenderer);

				//Go to next frame
				++frame;

				//Cycle animation
				if (frame / 4 >= WALKING_ANIMATION_FRAMES)
				{
					frame = 0;
				}
			}
		}
	}

	//Free resources and close SDL
	close();
}

void ImageProcessor::colorSquares(int** movement_squares, int max_move) {
	SDL_SetRenderDrawColor(gRenderer, 135, 206, 250, 0.2);
	SDL_Rect rect;
	rect.w = 32;
	rect.h = 32;
	for (int i = 0; i < map_controller->getMap()->getHeight(); i++) {
		for (int j = 0; j < map_controller->getMap()->getWidth(); j++) {
			if (movement_squares[i][j] <= max_move) {
				rect.x = j * DIST;
				rect.y = i * DIST;
				SDL_RenderFillRect(gRenderer, &rect);
			}
		}
	}
}