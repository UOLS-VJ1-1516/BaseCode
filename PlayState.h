#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "string"
#include <vector>

class PlayState : public GameState

{

public:

	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID()const;

private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;

};
