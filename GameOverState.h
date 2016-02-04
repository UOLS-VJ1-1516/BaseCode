#pragma once

#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include "game.h"
#include "MenuButton.h"
#include "string"
#include "StateParser.h"
#include "MenuState.h"

typedef void(*Callback)();

class GameOverState : public GameState {
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

	void setCallbacks(const std::vector<Callback >& callbacks);

private:
	static const std::string s_gameOverID;
	std::vector<GameObject* > m_gameObjects;
	static void s_gameOverToMain();
	std::vector<const char* > m_texturesIDList;
	std::vector<Callback > m_callbacks;

};

#endif