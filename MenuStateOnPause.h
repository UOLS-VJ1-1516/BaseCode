#pragma once
#include "GameState.h"
#include "MenuButton.h"


class MenuStateOnPause : public GameState
{
public:
	void update();
	void render();
	bool onEnter();
	void setCallbacks(const std::vector<Callback>& callbacks);
	bool onExit();
	std::string getStateID() const;
private:
	static const std::string s_menuID;
	std::vector<std::string> m_textureIDList;
	std::vector<GameObject*> m_gameObjects;
	std::vector<Callback> m_callbacks;
	static void s_menuToPlay();
	static void s_exitFromMenu();

};