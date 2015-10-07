#include "SDL.h"
#undef main

#include "Game.h"

int main(int argc, char* args[]) {
	Game joc;
	if (!joc.Init("Videojocs I", 100, 100, 640, 480, true)) {
		return 1;
	}
	while (joc.IsRunning()) {
		joc.EventHandler();
		joc.Update();
		joc.Render();
	}
	joc.Clear();
	return 0;
}
