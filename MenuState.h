#pragma once
#include "GameState.h"
#include "Game.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include <vector>

class MenuState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const;
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();

};