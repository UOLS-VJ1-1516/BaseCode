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
	static GameObject * Create() { return new Gordo(); }

};