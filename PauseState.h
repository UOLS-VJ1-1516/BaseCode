#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "player.h"
#include "Enemy.h"

class PauseState : public GameState {

public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;

private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;

	static void s_menuToPlay();
	static void s_menuToMain();

	Player* p1;
	Enemy* p2;
	Enemy* p3;

};