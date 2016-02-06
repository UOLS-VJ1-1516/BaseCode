#pragma once
#include <string>
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "String"
#ifndef MENUSTATE_H
#define MENUSTATE_H
typedef void(*Callback)();
class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const { return s_menuID; };
	typedef void (*callback);
private:
	static const std::string s_menuID;
	//std::vector<GameObject*> m_gameObjects;
	static void s_menuToPlay();
	static void s_exitFromMenu();
	virtual void setCallbacks(const std::vector<Callback>&callbacks);
	std::vector	<Callback> m_callbacksMenu;
protected:
	std::vector	<std::string> m_textureIDList;
	std::vector<GameObject*> m_gameObjectsMenuState;
};
#endif MENUSTATE_H
