#pragma once
#include "SDL.h"
#include "LoaderParams.h"
#include <iostream>
#include "Vector2.h"

class GameObject
{
public:
	virtual void load(LoaderParams* params) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleEvents(SDL_Event e) = 0;
	virtual void clean() = 0;
	virtual std::string getTextureId() = 0;
	virtual void setId(std::string newId) { id = newId; }
	virtual std::string getId() { return id; }

protected:
	GameObject();
	virtual ~GameObject();
	std::string id;
	Vector2 position;
	int width, height;
};