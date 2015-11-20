#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState * pState)
{
	//afegeixes un a la llista de m_gameState
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
	
}

void GameStateMachine::changeState(GameState * pState)
{
	//elimina tot el que esta a gameState i coloques el nou i elimnies al que estabes (statesToDelete)
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->getStateID() == pState->getStateID()) {
			return;
		}
		if (m_gameStates.back()->onExit()) {
				//m_statesToDelete.back();
				m_statesToDelete.push_back(m_gameStates.back());
				m_gameStates.pop_back();
		}
	}
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
	
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			m_statesToDelete.push_back(m_gameStates.back());
			m_gameStates.pop_back();
		}
	}
	//treu el ultim state (agafem el back i fem un pop back per eliminarlo i tornar al que estavem)
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty()) {
		m_gameStates.back()->update();
	}
	//criden al state actual Back
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
	//renderitzara el ultim
}
void GameStateMachine::AllStates() {
	m_statesToDelete.clear();
}
