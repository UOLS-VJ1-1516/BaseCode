#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "player.h"
#include "Enemy.h"
#include "LevelParser.h"

class PlayState : public GameState
{
public:
	void update();
	void render();

	bool onEnter();
	bool onExit();

	std::string getStateID() const;

private:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	std::vector< Callback > m_callbacks;

	static void s_menuToPlay();
	static void s_exitFromMenu();

	Player* p1;
	Enemy* p2;
	Enemy* p3;

	Level* pLevel;

};