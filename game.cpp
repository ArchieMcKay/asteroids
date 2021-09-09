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

	while (this->running) {	
		while (SDL_PollEvent(&e) != 0)
			if (e.type == SDL_QUIT)
				this->running = false;

		SDL_BlitSurface(this->blitSurface, NULL, this->screenSurface, NULL);
		SDL_UpdateWindowSurface(this->window);
	}

	return true;
}

bool Game::loadMedia() {
	this->blitSurface = SDL_LoadBMP("assets/pacman.bmp");

	return true;
}
