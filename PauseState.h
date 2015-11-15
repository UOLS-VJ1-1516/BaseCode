#pragma once
#include "string"
#include "GameState.h"
#include "MenuButton.h"
#include "Bottones.h"

class PauseState : public GameObject {
public:

	void update();
	void render();
	bool onEnter();
	bool onExit();

	std::string getStateID() const;

private:
	static const std::string s_pauseID;
	std::vector<GameObject*>m_gameObjects;
	static void s_menuTOPlay();
	static void s_menuTOMain();
	MenuButton* mb;
	MenuButton *mb2;
	MenuButton *mb3;

	Bottones *bo;
	Bottones *bo1;
	std::vector<int> mig(int width, int height);
	std::vector<int> m_position;
	

};