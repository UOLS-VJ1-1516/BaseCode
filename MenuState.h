#pragma once
#include "GameState.h"
#include "Game.h"
#include "string"
#include "MenuButton.h"
#include"GameObject.h"
#include "InputHandler.h"
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
	std::vector< GameObject* > m_gameObjects;
	MenuButton* buttonInit;
	MenuButton* buttonExit;
	InputHandler* TheInputHandler;
	static void s_menuToPlay();
	static void s_exitFromMenu();

	
};