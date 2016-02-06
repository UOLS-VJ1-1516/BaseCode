#pragma once
#include "GameState.h"
#include "vector"

#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

class GameStateMachine
{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();
private:
	std::vector< GameState* > m_gameStates;
	std::vector< GameState* > m_statesToDelete;
};
#endif GAMESTATEMACHINE_H
