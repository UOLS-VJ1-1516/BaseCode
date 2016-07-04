#pragma once
#include "GameState.h"
#include <string>
#include "Level.h"

class PlayState : public GameState {

public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	

private:
	static const std::string s_playID;
	static void s_menuTOplay();
	static void s_exitMenu();
	std::vector<GameObject*> m_gObjects;
	SDL_Renderer *m_pRenderer;

	

protected:
	typedef void(*Callback)();
	void setCallbacks(const std::vector<Callback>& callbacks);
	std::string getStateID() const;
	Level* m_level;

	std::vector< Callback > m_callbacks;
	std::vector<std::string> m_textureIDList;

};