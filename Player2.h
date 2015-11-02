#pragma once
#include "GameObject.h"

class Player2 : public GameObject
{
public:

	Player2();
	~Player2();
	void draw();
	void load(const LoaderParams* pParams);
	void load(int x, int y, int width, int height,
		std::string textureID);
	void update();
	void clean();
};
#pragma once
