#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>

class PlayState : public GameState
{
public:
	const int MAX_COLOR_VALUE = 255;

	PlayState();
	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event e);
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const;
	int red = 0, green = 0, blue = 0, alpha = 255;
private:
	const std::string stateID = "Level 1";
	std::vector<GameObject*> gameObjects;
};