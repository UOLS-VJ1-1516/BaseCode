#pragma once

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "GameState.h"
#include "GameObject.h"
#include "game.h"
#include "Player.h"
#include "Enemy.h"
#include "StaticObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "GameStateMachine.h"
#include "PauseState.h"
#include "GameObjectFactory.h"
#include "StateParser.h"


class PlayState : public GameState {
	public:
		virtual void update();
		virtual void render();

		virtual bool onEnter();
		virtual bool onExit();

		virtual std::string getStateID() const;

	private:
		static const std::string s_playID;
		std::vector<GameObject* > m_gameObjects; 
		std::vector<const char* > m_texturesIDList;

};

#endif
