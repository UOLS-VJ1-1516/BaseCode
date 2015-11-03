#pragma once
#include "LoaderParams.h"
#include <iostream>

class GameObject
{
public:
	virtual void load(LoaderParams* params) = 0;
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void setId(std::string newId) { id = newId; }
	virtual std::string getId() { return id; }

protected:
	GameObject();
	virtual ~GameObject();
	std::string id;
	float x, y;
	int width, height;
};