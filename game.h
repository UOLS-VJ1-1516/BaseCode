#include "SDL.h"
#include "SDL_image.h"

class Game
{
	SDL_Window* g_pWindow = 0;
	SDL_Renderer* g_pRenderer = 0;
	bool running = true;
	int spriteNum = 0, rowNum = 0;

	public:
		Game();
		~Game();
		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void render(int r, int g, int b);
		void update();
		void handleEvents(SDL_Event event);
		void clean();
		bool isRunning();
};
