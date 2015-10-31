#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();
	void draw(SDL_Renderer* pRender);
	void draw();
	void load(const LoaderParams* pParams);
	void load(int x, int y, int width, int height,
		std::string textureID);
	void update();
	void clean();
};
#pragma once
