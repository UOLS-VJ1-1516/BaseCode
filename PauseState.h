#pragma once

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "GameState.h"
#include "game.h"
#include "MenuButton.h"
#include "string"

class PauseState : public GameState {
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;

	private:
		static const std::string s_pauseID;
		std::vector<GameObject* > m_gameObjects;
		static void s_pauseToMain();
		static void s_resumePlay();
		MenuButton* resumeButton;
		MenuButton* mainMenuButton;

};

#endif