#include "SDL.h"
#include "SDL_image.h"


class Game
{
	SDL_Window* m_pWindow = 0;
	SDL_Renderer* m_pRenderer = 0;
	SDL_Surface* player;
	int pSprite = 0;
	int a ;
	int r;
	int g;
	int b;
	
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
