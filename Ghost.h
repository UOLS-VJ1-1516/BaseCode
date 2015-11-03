#pragma once
#ifndef GHOST_H
#define GHOST_H
#include "GameObject.h"
#include "SDL.h"

class Ghost : public GameObject	
{
public:
	Ghost();
	~Ghost();

	void load(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();
};

#endif GHOST_H