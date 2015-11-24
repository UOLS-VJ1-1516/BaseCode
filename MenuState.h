#pragma once
#include "GameObject.h"
#include "Game.h"
#include <string>
#include <vector>
#include "MenuButton.h"


class MenuState : public GameState {

public:

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_menuID; }
	static const std::string s_menuID;
	std::vector<GameObject*>m_gameObjects;
	static void s_Mplay();
	static void s_EMenu();
	std::vector<int> m_position;
	SDL_Renderer *m_pRenderer;



};