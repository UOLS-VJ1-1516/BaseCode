#include "game.h"
#include "TextureManager.h"

const int WINDOW_HEIGHT = 800;
const int WINDOW_WIDTH = 800;

game::game()
{
	g_pWindow = 0;
	imgRender = 0;
	running = false;

}

game::~game(){
}


bool game::init(const char* titulo, int xpos, int ypos, int typeWindow) {

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{		
		// Creo mi ventana
		g_pWindow = SDL_CreateWindow(titulo,xpos, ypos, WINDOW_WIDTH, WINDOW_HEIGHT,0);
		// Creo mi imagen en memoria
		if (g_pWindow != 0) imgRender = SDL_CreateRenderer(g_pWindow, -1, 0);
		// Añado mi imagen a mi lista de imagenes
		TextureManager::Instance()->load("hola.bmp", "hola", imgRender);
		// Indico que mi aplicación ha empezado
		running = true;
		return 0;
	}
		
	return 1;
}
	


void game::render() {
	// Elijo el color con que voy a pintar la pantalla
	SDL_SetRenderDrawColor(imgRender, 255, 255, 255, 255);
	// Limpio la pantalla con el color seleccionado.
	SDL_RenderClear(imgRender);
	// Obtengo un número entre el 0 y el 4
	mov = (int)((SDL_GetTicks() / 100) % 5);
	// llamo a drawFrame para que me actualice la imagen dependiendo del numero mov
	TextureManager::Instance()->drawFrame("hola", WINDOW_WIDTH / 2 - 40, WINDOW_HEIGHT / 2 - 100, 50, 200, mov, imgRender, SDL_FLIP_NONE);
}


void game::update() {

	//Mostra bufer pintat
	SDL_RenderPresent(imgRender);
	SDL_Delay(60);

}


void game::handleEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYUP) running = false;
		}
}


void game::clean() {

	SDL_RenderClear(imgRender);
	SDL_DestroyWindow(g_pWindow);
	SDL_DestroyRenderer(imgRender);
	SDL_Quit();
}


bool game::isRunning() { return running; }