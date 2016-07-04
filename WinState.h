
#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "GameObject.h"
#include <string>


typedef void(*Callback)();
class WinState : public GameState {
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();

	std::string getStateID() const;
	void setCallbacks(const std::vector<Callback>& callbacks);
private:
	static const std::string s_WinID;
	std::vector<GameObject*>m_gameObjects;
	static void s_menuTOPlay();
	static void s_menuTOMain();
	std::vector<int> m_position;

protected:
	typedef void(*Callback)();
	std::vector<Callback> m_callbacks;
	std::vector<std::string> m_textureIDList;

};

