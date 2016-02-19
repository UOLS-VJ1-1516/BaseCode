#pragma once

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "GameState.h"
#include "game.h"
#include "MenuButton.h"
#include "string"
#include "StateParser.h"
#include "InputHandler.h"

typedef void(*Callback)();

class PauseState : public GameState {
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;

		void setCallbacks(const std::vector<Callback >& callbacks);

	private:
		static const std::string s_pauseID;
		std::vector<GameObject* > m_gameObjects;
		static void s_pauseToMain();
		static void s_resumePlay();
		std::vector<const char* > m_texturesIDList;
		std::vector<Callback > m_callbacks;

};

#endif