#pragma once
#include <string>
#include "GameState.h"
#include <vector>
#include "GameObject.h"
#include "String"
typedef void(*Callback)();
class GameOverState : public GameState
{
public:
	GameOverState();
	~GameOverState();
	void update();
	void render();
	bool onEnter();
	bool onExit();
	std::string getStateID() const { return s_gameOverID; }
	typedef void(*callback);
private:
	static void s_gameOverToMain();
	static void s_restartPlay();
	static const std::string s_gameOverID;
	std::vector	<Callback> m_callbacksGameOver;
	virtual void setCallbacks(const std::vector<Callback>&callbacks);
protected:
	std::vector	<std::string> m_textureIDList;
	std::vector<GameObject*> m_gameObjectsGameOver;
};

