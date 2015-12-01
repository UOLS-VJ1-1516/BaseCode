#pragma once
#ifndef PAUSESTATE_H
#define PAUSESTATE_H
#include "Game.h"
#include "GameState.h"
#include "MenuButton.h"
#include "GameObject.h"

typedef void(*Callback)();

class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
	void setCallbacks(const std::vector<Callback>& callbacks);
private:
	static const std::string s_pauseID;
	std::vector<GameObject* > m_gameObjects;
	InputHandler* TheInputHandler;
	static void s_pauseToMain();
	static void s_resumePlay();
	std::vector<const char*> m_textureIDList;
	std::vector< Callback > m_callbacks;
};
#endif