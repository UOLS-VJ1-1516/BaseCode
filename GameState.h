#pragma once

#include <string>

#include "GameObject.h"
#include "TextureManager.h"
#include "Ghost.h"
#include "Player.h"
#include "SDL.h"
#include "InputHandler.h"

#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};

#endif GAMESTATE_H