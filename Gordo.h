#pragma once

#include "GameObject.h"
#include "LoaderParams.h"

class Gordo : public GameObject
{
	//int spriteNum;
public:
	Gordo();
	~Gordo(); //Cabecera
	virtual void draw();
	virtual void load(const LoaderParams* pParams);
	virtual void update();
	virtual void clean();
	virtual void onCollision(GameObject* other) {};
	static GameObject * Create() { return new Gordo(); }

};