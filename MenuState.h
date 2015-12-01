#pragma once

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"
#include "game.h"
#include "MenuButton.h"
#include "string"
#include "PlayState.h"
#include "StateParser.h"

typedef void(*Callback)();

class MenuState : public GameState {
	public:
		virtual void update();
		virtual void render();
		
		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;

		void setCallbacks(const std::vector<Callback >& callbacks);

	private:
		static const std::string s_menuID;
		std::vector<GameObject* > m_gameObjects;
		static void s_menuToPlay();
		static void s_exitFromMenu();
		std::vector<const char* > m_texturesIDList;
		std::vector<Callback > m_callbacks;

};

#endif