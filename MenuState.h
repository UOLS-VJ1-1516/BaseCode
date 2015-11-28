#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>

class MenuState : public GameState
{
public:
	MenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event e);
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const;
private:
	const std::string stateID = "MainMenu";
	std::vector<GameObject*> gameObjects;
	std::vector<std::string> textures;
	std::vector<void(*)()> callbacks;
	void (*callback) ();
	static void menuToPlay();
	static void exitFromMenu();
};