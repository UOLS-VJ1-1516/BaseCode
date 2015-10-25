#include "SDL.h"
#include "SDL_image.h"


class Game
{
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	SDL_Surface* tSurface;
	SDL_Texture* t;
	SDL_Rect  marcI;
	SDL_Rect  marcF;
	int a ;
	int r;
	int g;
	int b;
	//int spriteNum = 0;
	//int rowNum = 0;

public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int
		ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning();
};
