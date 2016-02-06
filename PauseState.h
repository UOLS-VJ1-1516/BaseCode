#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>
//#include "GameObject.h"

#ifndef PAUSESTATE_H
#define PAUSESTATE_H

typedef void(*Callback)();
class PauseState : public GameState
{
public:
	PauseState();
	~PauseState();

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	void setCallbacks(const std::vector<Callback>&callbacks);
	std::vector	<Callback> m_callbacksPause;
protected:
	std::vector	<std::string> m_textureIDList;
	std::vector<GameObject*> m_gameObjectsPauseState;
};
#endif PAUSESTATE_H


