#include "SDL.h"

class game
{

	//declaramos las variables tal y como estaban en el main.cpp
	bool on = true;
	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;
	SDL_Surface* textureSurface;
	SDL_Texture* texture;
	SDL_Rect  rectanguloFuente;
	SDL_Rect  rectanguloDestino;


	

	//creamos las funciones que se piden en el pdf

public:
	game();
	~game();
	bool init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render(int a, int b, int c);
	void update();
	void handleEvents();
	void clean();
	bool isRunning();

};

