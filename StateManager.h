#pragma once
#include <iostream>
#include "GameStates.h"

class StateManager
{
private:
	std::vector<GameState *> gameStates;
	std::vector<GameState *> gsDelete;
public:
	StateManager();

	void PushState(GameState * state);
	void ChangeState(GameState * state);
	void PopState();

	~StateManager();

	void HandleEvents();
	void Update();
	void Render();
};