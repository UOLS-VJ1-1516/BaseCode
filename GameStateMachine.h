#pragma once
#include "GameState.h"
#include "vector"

//Clase para controlar los diferentes estados del juego
class GameStateMachine
{
	public:
		void pushState(GameState* pState);
		void changeState(GameState* pState);
		void popState();
		void update();
		void render();
		void deleteAllStates();

	private:
		std::vector<GameState*> m_gameStates;
		std::vector<GameState*> m_statesToDelete;
};