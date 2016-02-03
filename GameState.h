#pragma once
#include "iostream"
#include "Fons.h"
#include "Enemy.h"
#include <vector>
#include "Player.h"
#include "GameObject.h"


typedef void(*Callback)();
class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	//virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;
	virtual std::string getStateID() const = 0;
};