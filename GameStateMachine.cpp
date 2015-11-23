#include "GameStateMachine.h"

//Función para crear un nuevo estado
void GameStateMachine::pushState(GameState* pState) {
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
};

//Función para cambiar de estado que pasa el anterior al vector de estados eliminados y crea el nuevo
void GameStateMachine::changeState(GameState* pState) {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->getStateID() == pState->getStateID()) {
			return;
		}
		if (m_gameStates.back()->onExit()) {
			m_statesToDelete.push_back(m_gameStates.back());
			m_gameStates.pop_back();
		}
	}
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
};

//Función para eliminar el estado actual
void GameStateMachine::popState() {
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			//m_statesToDelete.back();
			m_statesToDelete.push_back(m_gameStates.back());
			m_gameStates.pop_back();
		}
	}
};

//Función para updatear el estado
void GameStateMachine::update() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->update();
	}
};

//Función para mostrar el estado
void GameStateMachine::render() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
};

//Función para limpiar el vector de los estados eliminados al finalizar el juego
void GameStateMachine::deleteAllStates() {
	m_statesToDelete.clear();
};