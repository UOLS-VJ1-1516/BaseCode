#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState) {
	pState->onEnter();
	m_gameStates.push_back(pState);
};

void GameStateMachine::changeState(GameState* pState) {
	m_gameStates.back()->onExit();
	m_gameStates.push_back(pState);
	pState->onEnter();
};

void GameStateMachine::popState() {
	m_gameStates.back()->onExit();
	m_gameStates.pop_back();
};

void GameStateMachine::update() {
	for (std::vector<GameState*>::size_type i = 0; i < m_gameStates.size(); i++) {
		m_gameStates[i]->update();
	}
};

void GameStateMachine::render() {
	for (std::vector<GameState*>::size_type i = 0; i < m_gameStates.size(); i++) {
		m_gameStates[i]->render();
	}
};