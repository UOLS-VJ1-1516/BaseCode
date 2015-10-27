#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	std::string textureID;
	std::string getTextureId();
};
