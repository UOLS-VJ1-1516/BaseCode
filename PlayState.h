#pragma once
#ifndef PLAYSTATE_H
#define PLAYSTATE_H
#include "GameState.h"
#include "LoaderParams.h"
#include "GameObject.h"
#include "vector"
#include "TextureManager.h"
#include "Game.h"
#include "InputHandler.h"
#include "TileLayer.h"


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
	std::vector< GameObject* > m_gameObjects;
	std::vector< const char * > m_textureIDList;
	TileLayer* til;
};
#endif