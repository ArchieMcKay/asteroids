#ifndef GAME_H
#define GAME_H

#include "main.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

enum KeyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

class Game {
public:
	bool running;
	SDL_Surface* keyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
	SDL_Surface* currentSurface;

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
	SDL_Surface* loadSurface(std::string path);
};

#endif
