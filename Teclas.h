#pragma once
#include "CollisionObject.h"
#ifndef TECLAS_H
#define TECLAS_H

class Teclas : public CollisionObject
{
public:
	Teclas();
	~Teclas();
	void draw(SDL_Renderer* lRender);
	void draw();
	void load(const LoadPar* lPar);
	void load(float x, float y, int width, int height, std::string texid);
	void update();
	void clean();
	static GameObject * Create() { return new Teclas(); }

private:
	const LoadPar * Params;
};
#endif TECLAS_H