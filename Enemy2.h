#pragma once
#ifndef ENEMY2_H
#define ENEMY2_H
#include "GameObject.h"
#include "LoaderParams.h"

class Enemy2 : public GameObject {
public:
	Enemy2();
	~Enemy2(); //Cabecera
	void draw();
	void load(const LoaderParams* pParams);
	void update();
	void clean();
};
#endif
#pragma once
