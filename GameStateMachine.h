#pragma once

#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "GameState.h"
#include "vector"

class GameStateMachine {
	public:
		void pushState(GameState* pState);
		void changeState(GameState* pState);
		void popState();

		void update();
		void render();

		void deleteOldStates();

	private:
		std::vector<GameState* > m_gameStates;
		std::vector<GameState* > m_statesToDelete;

};

#endif
