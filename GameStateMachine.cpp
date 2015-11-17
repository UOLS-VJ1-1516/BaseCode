#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState * pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState * pState)
{ 
	std::cout << "change State\n";
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
		if (m_gameStates.back()->onExit())
		{
			m_statesToDelete.push_back(m_gameStates.back());
			m_gameStates.pop_back();
		}
	}
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
	//elimina (m_stateToDelete) el change state y coloques el nou pState(
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->onExit()) {
			m_statesToDelete.push_back(m_gameStates.back());
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::update()
{
	//en funció del últim element m_gameState.back
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::voidAllOldStates()
{
	m_statesToDelete.clear();
}
