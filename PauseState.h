#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PauseState : public GameState
{
public:

	PauseState();
	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event e);
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const;

private:
	const std::string stateID = "Pause";
	std::vector<GameObject*> gameObjects;
	static void resumeGame();
	static void exitToMenu();
};