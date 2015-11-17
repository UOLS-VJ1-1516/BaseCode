#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <string>
#include <vector>
#include "MenuButton.h"


class MenuState : public GameState{

public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:
	static const std::string s_menuID;
	std::vector<GameObject*>m_gameObjects;
	static void s_menuTOplay();
	static void s_exitMenu();
	std::vector<int> m_position;
	SDL_Renderer *m_pRenderer;
};