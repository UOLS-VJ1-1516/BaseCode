#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "GameObject.h"
#include <string>

class PauseState : public GameState {
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

	std::vector<int> m_position;

};
