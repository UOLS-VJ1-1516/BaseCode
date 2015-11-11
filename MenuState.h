#pragma once
#include "string"
#include "GameState.h"
#include "GameObject.h"

#ifndef MENUSTATE_H
#define MENUSTATE_H

class MenuState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
};
#endif MENUSTATE_H