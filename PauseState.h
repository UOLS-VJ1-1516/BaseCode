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
	const std::string stateID = "PAUSE";
	std::vector<GameObject*> gameObjects;
	std::vector<std::string> textures;
	std::vector<void(*)()> callbacks;
	static void resumeGame();
	static void exitToMenu();
};