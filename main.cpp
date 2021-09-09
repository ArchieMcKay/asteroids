#include "main.h"
#include "game.h"

int main(int argc, char* argv[]) {
	Game game = Game();

	game.loadMedia();
	SDL_BlitSurface(game.blitSurface, NULL, game.screenSurface, NULL);

	SDL_UpdateWindowSurface(game.window);

	SDL_Delay(2000);

	return 0;
}
