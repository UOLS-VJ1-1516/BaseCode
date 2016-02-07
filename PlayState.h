#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "TileLayer.h"

class PlayState : public GameState
{

public:

	void update();
	void render();
	bool onEnter();
	void setCallbacks(const std::vector<Callback>& callbacks);
	bool onExit();
	std::string getStateID()const;

private:

	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	std::vector<std::string> m_textureIDList;
	std::vector<Callback> m_callbacks;
	Level* tiled;

};
