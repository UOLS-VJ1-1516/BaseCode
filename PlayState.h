#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "vector"

//Clase State de Play para entrar el juego
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
		GameObject* player;
		GameObject* enemy1;
		GameObject* enemy2;
		GameObject* enemy3;
};