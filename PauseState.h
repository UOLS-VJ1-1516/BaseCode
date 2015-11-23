#pragma once
#include "GameState.h"
#include "vector"
#include "GameObject.h"

//Clase con el estado Pause para pausar el juego que te da la opcion de continuar o volver al estado de menu
class PauseState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID; }
private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
	GameObject* button1;
	GameObject* button2;
};