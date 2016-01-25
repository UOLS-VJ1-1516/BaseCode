#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "MenuButton.h"


//Clase del estado menu donde se puede empezar a jugar o salir del juego
class MenuState : public GameState
{
	protected:
		typedef void(*Callback)();
		virtual void setCallbacks(const std::vector<Callback>& callbacks);
		std::vector<Callback> m_callbacks;
	public:
		virtual void update();
		virtual void render();
		virtual bool onEnter();
		virtual bool onExit();
		virtual std::string getStateID() const { return s_menuID; }
	private:
		static void s_menuToPlay();
		static void s_exitFromMenu();

		static const std::string s_menuID;
		std::vector<GameObject*> m_gameObjects;
		GameObject* button1;
		GameObject* button2;
};