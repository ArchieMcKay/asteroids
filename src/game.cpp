#include "game.h"

Game::Game() {
	SDL_Init(SDL_INIT_VIDEO);
	this->window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	this->screenSurface = SDL_GetWindowSurface(this->window);
	this->running = true;
}

Game::~Game() {
	SDL_FreeSurface(this->blitSurface);
	this->blitSurface = NULL;

	SDL_DestroyWindow(this->window);
	this->window = NULL;

	SDL_Quit();
}

bool Game::gameLoop() {
	this->loadMedia();

	SDL_Event e;

	this->currentSurface = this->keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];

	while (this->running) {	
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				this->running = false;
			} else if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_UP:
					this->currentSurface = this->keyPressSurfaces[KEY_PRESS_SURFACE_UP];
					break;
				case SDLK_DOWN:
					this->currentSurface = this->keyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					break;
				case SDLK_LEFT:
					this->currentSurface = this->keyPressSurfaces[KEY_PRESS_SURFACE_LEFT];
					break;
				case SDLK_RIGHT:
					this->currentSurface = this->keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT];
					break;
				}
			}
		}

		SDL_Rect stretchRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
		SDL_BlitScaled(this->currentSurface, NULL, this->screenSurface, &stretchRect);
		SDL_UpdateWindowSurface(this->window);
	}

	return true;
}

bool Game::loadMedia() {
	this->keyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("assets/press.bmp");
	this->keyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("assets/up.bmp");
	this->keyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("assets/down.bmp");
	this->keyPressSurfaces[KEY_PRESS_SURFACE_LEFT] = loadSurface("assets/left.bmp");
	this->keyPressSurfaces[KEY_PRESS_SURFACE_RIGHT] = loadSurface("assets/right.bmp");

	return true;
}

SDL_Surface* Game::loadSurface(std::string path) {
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	SDL_Surface* optimisedSurface = SDL_ConvertSurface(loadedSurface, this->screenSurface->format, 0);

	SDL_FreeSurface(loadedSurface);
	return optimisedSurface;
}
