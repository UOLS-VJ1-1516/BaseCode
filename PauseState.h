#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "InputHandler.h"
#include "texturemanager.h"
#include "game.h"

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
	std::vector<GameObject*> m_gameObjects;
	static void s_pauseToMain();
	static void s_resumePlay();
};
