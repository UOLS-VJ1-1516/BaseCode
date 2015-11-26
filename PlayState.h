#pragma once
#include "GameState.h"
#include "SDL_image.h"




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
	std::vector<GameObject*> m_gameObjects;
	LoadPar * load;
	LoadPar * load2;
	LoadPar * load3;
	LoadPar * load4;
		
	Player * player;
	Enemy * enemy1;
	Enemy * enemy2;
	Enemy * enemy3;
	Enemy * coin;
	Fons * nubes1;
	Fons * nubes2;
	SDL_Renderer *m_pRenderer;




};