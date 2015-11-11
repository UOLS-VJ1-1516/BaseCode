#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState) {
	m_gameStates.push_back(pState);
	//m_gameState = std::vector< GameState* >;

};
void GameStateMachine::changeState(GameState* pState) {
	m_gameStates.back()->onExit;
	/*for (m_gameStates.length) {

	}*/
	m_gameStates.push_back(pState);
	pState->onEnter();
};

void GameStateMachine::popState() {

};

void GameStateMachine::update() {

};
void GameStateMachine::render() {

};