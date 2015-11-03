#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDL.h"
#ifndef DOG_H
#define DOG_H
class Dog :
	public GameObject
{
public:
	Dog();
	~Dog();
	//void load(const LoaderParams* pParams);
	void load(int x, int y, int width, int height, const char* textureID);
	void draw();
	void update();
	void clean();
};
#endif DOG_H

