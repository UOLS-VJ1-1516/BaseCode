#pragma once
#include "GameState.h"
#include "vector"
#include "GameObject.h"

class PauseState : public GameState
{
protected:
	typedef void(*Callback)();
	virtual void setCallbacks(const std::vector<Callback>& callbacks);
	std::vector<Callback> m_callbacks;
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
	GameObject* button1;
	GameObject* button2;
};