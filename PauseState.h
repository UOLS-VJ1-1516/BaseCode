#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "player.h"
#include "Enemy.h"
#include <vector>

class PauseState : public GameState {

public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

private:
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
	std::vector< Callback > m_callbacks;

	static void s_menuToPlay();
	static void s_menuToMain();

	Player* p1;
	Enemy* p2;
	Enemy* p3;

};