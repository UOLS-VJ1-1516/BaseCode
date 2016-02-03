#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include "GameObject.h"
#include <string>

typedef void(*Callback)();
class GameOverState : public GameState {
public:
	void update();
	void render();
	bool onEnter();
	bool onExit();
	void setCallbacks(const std::vector<Callback>&callbacks);
	std::string getStateID() const;
private:
	static const std::string s_gameOverID;
	std::vector<GameObject*>m_gameObjects;
	static void s_menuTOMain();
	std::vector<GameObject*> m_gObjects;
	std::vector<std::string> m_TextureIDList;
	std::vector<void(*)()> m_callbacks;
	std::vector<int> m_position;

	std::vector<Callback>m_callbacksID;


};

