#pragma once
#include <iostream>
#include <vector>
#include "GameState.h"
#include "MenuButton.h"

class MenuState : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const;
	

private:
	static const std::string s_menuID;

	std::vector<GameObject*> m_gameObjects;
	std::vector<int> theMiddle(int width, int height);
	std::vector<int> m_position;
	std::vector<std::string> idTextures;
	std::vector<void(*)()> callbacks;

	static void s_menuToPlay();
	static void s_exitFromMenu();
	MenuButton* mb;
	MenuButton* mb2;
	
	StaticObjects* so;
	
};