#pragma once
#include "GameState.h"
#include "Vector"
class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
	void cleanState();

private:
	std::vector< GameState* > m_gameStates;
	std::vector< GameState* > m_statesToDelete;
	
	
};