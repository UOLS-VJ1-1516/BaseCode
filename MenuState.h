#pragma once

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include "game.h"
#include "MenuButton.h"
#include "string"

class MenuState : public GameState {
	public:
		void update();
		void render();

		bool onEnter();
		bool onExit();

		std::string getStateID() const;

	private:
		static const std::string s_menuID;
		std::vector<GameObject* > m_gameObjects;
		static void s_menuToPlay();
		static void s_exitFromMenu();
		MenuButton* startButton;
		MenuButton* exitButton;

};

#endif