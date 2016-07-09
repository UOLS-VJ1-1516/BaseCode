#pragma once
#include "GameState.h"
#include "game.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "Player.h"
#include "Enemy.h"

class PlayState : public GameState
{
public:

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	
private:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	
	bool checkCollision(GameObject* p1, GameObject* p2);

};
