#pragma once
#ifndef PAUSESTATE_H
#define PAUSESTATE_H
#include "Game.h"
#include "GameState.h"
#include "MenuButton.h"

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static const std::string s_pauseID;
	std::vector<GameObject* > m_gameObjects;
	InputHandler* TheInputHandler;
	MenuButton* buttonResume;
	MenuButton* buttonMenu;
	static void s_pauseToMain();
	static void s_resumePlay();
};
#endif