#pragma once
#include "string"
#include "GameState.h"
#include "MenuButton.h"

#ifndef GAMEOVER_H
#define GAMEOVER_H

typedef void (*Callback)();

class GameOver : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
	void setCallbacks(const std::vector<Callback>& callbacks);
private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	std::vector<int> m_position;
	std::vector<const char*> m_textureIDList;
	std::vector< Callback > m_callbacks;
};
#endif GAMEOVER_H