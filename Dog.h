#pragma once
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDL.h"
#ifndef DOG_H
#define DOG_H
class Dog : public GameObject
{
public:
	Dog();
	~Dog();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	static GameObject * Create() { return new Dog(); }
protected:
	const LoaderParams *pParams;
};
#endif DOG_H

