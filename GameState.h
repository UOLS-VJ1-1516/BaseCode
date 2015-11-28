#pragma once
#include "iostream"
#include "Player.h"
#include "Enemy.h"
#include "GameObject.h"
#include "vector"

class GameState {

public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};
