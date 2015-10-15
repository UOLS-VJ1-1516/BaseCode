#include "Game.h"

int main(int argc, char* args[])
{
	Game game = Game();

	if (game.init("Videjuegos 1 - bachelor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, false)) {
		while (game.isRunning()) {
			game.render();
			game.clean();
			game.update();
			game.handleEvents();
		}
	}

	game.~Game();
	return 0;
}
//	// everything succeeded lets draw the window
//	// set to black // This function expects Red, Green, Blue and
//	// Alpha as color values
//
//	Uint32 start = SDL_GetTicks();
//	Uint32 lastTime = SDL_GetTicks();
//	int tiempo = 0;
//
//	while (true) {
//
//		SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
//
//
//		// clear the window to black
//		SDL_RenderClear(g_pRenderer);
//
//		int numeroDivisiones = 6;
//		int numeroPixelesDivision = *pixelesDeAncho / 6;
//		int pixel = 0;
//		int divisionActual = 0;
//		tiempo += SDL_GetTicks() - lastTime;
//		lastTime = SDL_GetTicks();
//		for (pixel = 0; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
//			SDL_SetRenderDrawColor(g_pRenderer, 255, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 0, 255); //Rojo a Amarillo
//			SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
//		}
//		divisionActual++;
//		for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
//			SDL_SetRenderDrawColor(g_pRenderer, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255, 0, 255); //Amarillo a Verde
//			SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
//		}
//		divisionActual++;
//		for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
//			SDL_SetRenderDrawColor(g_pRenderer, 0, 255, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255); //Verde a Cyan
//			SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
//		}
//		divisionActual++;
//		for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
//			SDL_SetRenderDrawColor(g_pRenderer, 0, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255, 255); //Cyan a Blue
//			SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
//		}
//		divisionActual++;
//		for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
//			SDL_SetRenderDrawColor(g_pRenderer, (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 0, 255, 255); //Blue a Lila
//			SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
//		}
//		divisionActual++;
//		for (; pixel < numeroPixelesDivision*(divisionActual + 1); pixel++) {
//			SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 255 - (Uint8)(255 * (pixel - numeroPixelesDivision*divisionActual) / numeroPixelesDivision), 255); //Lila a Rojo
//			SDL_RenderDrawLine(g_pRenderer, (pixel + tiempo) % *pixelesDeAncho, 0, (pixel + tiempo) % *pixelesDeAncho, *pixelesDeAlto);
//		}
//
//		// show the window
//		SDL_RenderPresent(g_pRenderer);
//	}
//
//	// clean up SDL
//	SDL_Quit();
//}
