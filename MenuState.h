#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <string>
#include <vector>
#include "SDL_image.h"
#include "MenuButton.h"

#ifndef MENUSTATE_H
#define MENUSTATE_H


class MenuState : public GameState {

public:
	 void update();
	 void render();
	 bool onEnter();
	 bool onExit();
	std::string getStateID() const;
	void setCallbacks(const std::vector<Callback>& callbacks);

private:
	static const std::string s_menuID;
	std::vector<GameObject*>m_gameObjects;
	static void s_menuTOplay();
	static void s_exitMenu(); 
	std::vector<int> m_position;
	SDL_Renderer *m_lRenderer;
	std::vector<std::string> m_textureIDList;
	std::vector<Callback> m_callbacks;
	

	
}; 

#endif MENUSTATE_H