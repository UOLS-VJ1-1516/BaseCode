#pragma once

#include "GameObject.h"
#include "LoaderParams.h"

class Zep : public GameObject
{
	//int spriteNum;
public:
	Zep();
	~Zep(); //Cabecera
	virtual void draw();
	virtual void load(const LoaderParams* pParams);
	virtual void update();
	virtual void clean();
	virtual void onCollision(GameObject* other) {};
	static GameObject * Create() { return new Zep(); }

	

};
