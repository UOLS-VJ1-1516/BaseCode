#pragma once
#include "SDL.h"
#include "String"


class GameObject
{
public:
	
	virtual ~GameObject();
	virtual void load(int x, int y, int width, int height,
		std::string textureID)=0;
	virtual void draw() = 0;//si la posem = 0 fem que sigui una funcio buida i no es pugui instanciar Virtual Pura
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	GameObject();
	virtual ~GameObject();

};