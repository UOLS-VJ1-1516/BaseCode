#pragma once
#include "GameState.h"
#include <string>

class PlayState : public GameState {

public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; };

private:
	static const std::string s_playID;
	static void s_menuTOplay();
	static void s_exitMenu();
	std::vector<GameObject*> m_gObjects;
	LoaderParams * load;
	Player * player;
	LoaderParams * load2;
	Enemy * enemy1;
	LoaderParams * load3;
	Enemy * borot;
	SDL_Renderer *m_pRenderer;
};

