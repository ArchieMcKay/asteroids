#include "game.h"

Game::Game() {
	SDL_Init(SDL_INIT_VIDEO);
	this->window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	this->screenSurface = SDL_GetWindowSurface(this->window);
}

Game::~Game() {
	SDL_FreeSurface(this->blitSurface);
	this->blitSurface = NULL;

	SDL_DestroyWindow(this->window);
	this->window = NULL;

	SDL_Quit();
}

bool Game::loadMedia() {
	this->blitSurface = SDL_LoadBMP("assets/pacman.bmp");

	return true;
}
