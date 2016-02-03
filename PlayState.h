#pragma once
#include "GameState.h"
#include <string>

class PlayState : public GameState {

public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	
	std::string getStateID() const;

private:
	static const std::string s_playID;
	static void s_menuTOplay();
	static void s_exitMenu();
	std::vector<GameObject*> m_gObjects;
	SDL_Renderer *m_pRenderer;
	std::vector<std::string> m_textureIDList;




};