#include "main.h"
#include "game.h"

int main(int argc, char* argv[]) {
	Game game = Game();

	game.gameLoop();

	return 0;
}
