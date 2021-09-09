#ifndef GAME_H
#define GAME_H

#include "main.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Game {
public:
	Game();
	~Game();

public:
	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Surface* blitSurface;

	bool loadMedia();

private:

};


#endif
