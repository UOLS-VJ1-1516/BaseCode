#pragma once
#include "GameState.h"
#include <vector>
#include "SDL.h"

class GameStateMachine
{
public:
	GameStateMachine();
	GameStateMachine(GameState* State);
	void pushState(GameState* State);
	void changeState(GameState* State);
	void popState();
	void update();
	void render();
	void handleEvents(SDL_Event e);
	void clean();
private:
	std::vector< GameState* > gameStates;
	std::vector< GameState* > statesToDelete;
};