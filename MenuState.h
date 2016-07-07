#pragma once
#include"GameState.h"
#include "GameObject.h"
#include "texturemanager.h"
#include "Game.h"
#include "MenuButton.h"

class MenuState : public GameState
{
	public:
		virtual void update();
		virtual void render();
		virtual bool onEnter();
		virtual bool onExit();
		virtual std::string getStateID() const { return s_menuID; }

	private:
		static const std::string s_menuID;
		std::vector<GameObject*> m_gameObjects;

		static void s_menuToPlay();
		static void s_exitFromMenu();

};