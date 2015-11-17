#pragma once
#include <iostream>
#include <vector>
#include "AllEntities.hpp"
#include <SDL.h>
#include "Button.h"
#include "EventHandler.h"

using namespace std;

class GameState
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void HandleEvents() = 0;

	virtual bool OnEnter() = 0;
	virtual bool OnExit() = 0;

	virtual string GetStateID() const = 0;
};


class StateGame : public GameState
{
private:
	string gameID;
	vector<Entity *> entitats;
	Player * player = NULL;	
public:
	void Update();
	void Render();
	void HandleEvents();

	bool OnEnter();
	bool OnExit();

	string GetStateID() const { return gameID; }
};

class StateMenu : public GameState
{
private:
	string menuID;
	vector<Entity *> entitats;
public:
	StateMenu();

	void Update();
	void Render();
	void HandleEvents();

	bool OnEnter();
	bool OnExit();

	string GetStateID() const
	{
		return menuID;
	}
};

class StatePause : public GameState
{
private:
	string pauseID;
	vector<Entity *> entitats;
public:
	StatePause();

	void Update();
	void Render();
	void HandleEvents();

	bool OnEnter();
	bool OnExit();

	string GetStateID() const
	{
		return pauseID;
	}
};