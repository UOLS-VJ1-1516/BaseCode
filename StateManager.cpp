#include "StateManager.h"

using namespace std;

StateManager::StateManager()
{
	GameState * state = new StateMenu();
	PushState(state);
}

void StateManager::PushState(GameState * state)
{
	state->OnEnter();
	gameStates.push_back(state);
}

void StateManager::ChangeState(GameState * state)
{
	gsDelete.push_back(gameStates.back());
	gameStates.back() = state;
}

void StateManager::PopState()
{
	gameStates.back()->OnExit();
	gsDelete.push_back(gameStates.back());
	gameStates.pop_back();
}

StateManager::~StateManager()
{
	gameStates.clear();
	gsDelete.clear();
}

void StateManager::HandleEvents()
{
	gameStates.back()->HandleEvents();
}

void StateManager::Update()
{
	gameStates.back()->Update();
}

void StateManager::Render()
{
	gameStates.back()->Render();
}