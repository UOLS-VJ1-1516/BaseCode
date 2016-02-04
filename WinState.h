#pragma once
#ifndef WINSTATE_H
#define WINSTATE_H

#include "GameState.h"
#include "game.h"
#include "MenuButton.h"
#include "string"
#include "StateParser.h"
#include "MenuState.h"

typedef void(*Callback)();

class WinState : public GameState {
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

	void setCallbacks(const std::vector<Callback >& callbacks);

private:
	static const std::string s_winID;
	std::vector<GameObject* > m_gameObjects;
	static void s_winToMain();
	std::vector<const char* > m_texturesIDList;
	std::vector<Callback > m_callbacks;

};

#endif