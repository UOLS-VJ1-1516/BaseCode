#pragma once
#include "GameObject.h"
class Player : public GameObject
{
	int spriteNum;
public:
	Player() {};
	~Player() {};
	void draw(SDL_Renderer* pRender)
	{

		GameObject::draw();
		
	}
	
};
