#include "game.h"

const int P_ANC = 640;
const int P_ALT = 480;


void cambioColor(int &r, int &g, int &b) {

	if ((r > 0) && (b == 0)) {
		r--;
		g++;
	}

	if ((g > 0) && (r == 0)) {
		g--;
		b++;
	}

	if ((g == 0) && (b > 0)) {
		b--;
		r++;
	}

}


int main(int argc, char* args[])
{
	int r = 255;
	int g = 0;
	int b = 0;

	Game game;
	
	if (game.init("Videjuegos 1 - bachelor",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		P_ANC, P_ALT, SDL_WINDOW_FULLSCREEN)) {

		while (game.isRunning())
		{
			game.handleEvents();
			//game.update();
			game.render(r, g, b);
			cambioColor(r, g, b);

		}

		game.clean();
	}
	return 0;
}
