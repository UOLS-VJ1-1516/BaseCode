#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <vector>
#include "PauseState.h"
#include "Level.h"

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

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
	std::vector<GameObject*> m_gameObjectsPlay;
	static void s_playToPause();
	//GameObject* player;
	//GameObject* dog;
	std::vector<LoaderParams*> loader;
	//LoaderParams* l1;
	//LoaderParams* l2;
	
protected:
	std::vector	<std::string> m_textureIDList;
	Level* ppLevel;
};
#endif PLAYSTATE_H