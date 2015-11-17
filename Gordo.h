#pragma once
#ifndef GORDO_H
#define GORDO_H
#include "GameObject.h"
#include "LoaderParams.h"

class Gordo : public GameObject
{
	//int spriteNum;
public:
	Gordo();
	~Gordo(); //Cabecera
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();

};
#endif#pragma once
