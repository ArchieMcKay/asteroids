#ifndef GAME_H
#define GAME_H

#include "main.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Game {
public:
	bool running;

public:
	Game();
	~Game();

	bool gameLoop();

private:
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Surface* blitSurface;

private:
	bool loadMedia();
};


#endif
