#pragma once
#include "GameObject.h"

#ifndef GHOST_H
#define GHOST_H

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