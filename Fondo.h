#pragma once
#include "GameObject.h"
#ifndef FONDO_H
#define FONDO_H

class Fondo : public GameObject
{
public:
	Fondo();
	~Fondo();
	void draw(SDL_Renderer* lRender);
	void draw();
	void load(const LoadPar* lPar);
	void load(int x, int y, int width, int height, std::string texid);
	void update();
	void clean();
};
#endif FONDO_H