#pragma once
#ifndef ZEP_H
#define ZEP_H
#include "GameObject.h"
#include "LoaderParams.h"

class Zep : public GameObject
{
	//int spriteNum;
public:
	Zep();
	~Zep(); //Cabecera
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();

};
#endif