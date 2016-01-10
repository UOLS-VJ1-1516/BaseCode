#pragma once

#include "GameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"

class Player : public GameObject
{
	//int spriteNum;
public:
	
	Player();
	~Player(); //Cabecera
	virtual void draw();
	virtual void load(const LoaderParams* pParams);
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new Player(); }

};
