#pragma once
#include "GameState.h"
#include "GameObject.h"
#include <string>
#include "SDL_image.h"
#include "MenuButton.h"

#ifndef MENUSTATE_H
#define MENUSTATE_H

typedef void(*Callback)();
class MenuState : public GameState {

public:
	 std::string getStateID() const;
    
	 void update();
	 void render();
	 bool onEnter();
	 bool onExit();
	

private:
	static const std::string s_menuID;
	std::vector<GameObject*>m_gameObjects;
	static void s_menuTOplay();
	static void s_exitMenu(); 
	std::vector<int> m_position;
	SDL_Renderer *m_lRenderer;
	std::vector<std::string> m_textureIDList;
	std::vector< Callback > m_callbacks;
	
protected:
	void setCallbacks(const std::vector<Callback>& callbacks);
	
}; 

#endif MENUSTATE_H