#include "GameStateMachine.h"

GameStateMachine::GameStateMachine() {}

GameStateMachine::GameStateMachine(GameState * State) {
	pushState(State);
}

void GameStateMachine::pushState(GameState * State) {
	cleanBrush();
	State->onEnter();
	gameStates.push_back(State);
}

void GameStateMachine::changeState(GameState * State) {
	for (int i = 0; i < gameStates.size(); i++)
		statesToDelete.push_back(gameStates[i]);
	gameStates.clear();
	State->onEnter();
	gameStates.push_back(State);
}

void GameStateMachine::popState() {
	cleanBrush();
	statesToDelete.push_back(gameStates.back());
	gameStates.pop_back();
}

void GameStateMachine::update() {
	if (!gameStates.empty())
		gameStates.back()->update();
}

void GameStateMachine::render() {
	if (!gameStates.empty())
		gameStates.back()->render();
}

void GameStateMachine::handleEvents(SDL_Event e) {
	gameStates.back()->handleEvents(e);
}

void GameStateMachine::clean() {
	for each (GameState * gs in gameStates)
		gs->onExit();
	gameStates.clear();
}

void GameStateMachine::cleanBrush() {
	for each (GameState * gs in statesToDelete)
		gs->onExit();
	statesToDelete.clear();
}
