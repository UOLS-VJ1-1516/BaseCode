#pragma once
#include "GameObject.h"
#ifndef FONS_H
#define FONS_H

class Fons : public GameObject
{
public:
	Fons();
	~Fons();
	void draw(SDL_Renderer* lRender);
	void draw();
	void load(const LoadPar* lPar);
	void load(float x, float y, int width, int height, std::string texid);
	void update();
	void clean();
	static GameObject * Create() { return new Fons(); }
};
#endif  FONS_H
