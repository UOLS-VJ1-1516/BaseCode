#pragma once
#include "string"
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "StaticObjects.h"
#include "Enemy.h"
#include "SDL.h"

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

class PlayState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
private:
	static const std::string s_menuID;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	std::vector<GameObject*> m_gobjects;
	LoaderParams* lp;
	Player* p;
	LoaderParams* lo;
	StaticObjects* o;
	LoaderParams* le;
	Enemy* e;
	Enemy* e2;
	Enemy* e3;
	Enemy* e4;
};

#endif PLAYSTATE_H
