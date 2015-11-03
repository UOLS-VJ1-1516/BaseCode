#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	int spriteCol, spriteRow, nCols, nRows;

public:
	Player(std::string id);
	virtual ~Player();
	virtual void load(LoaderParams* params);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void setTexture(std::string textureID, std::string texturePath, int nCols, int nRows);
	std::string getTextureId();
	std::string getTexturePath();

private:
	std::string textureID;
	std::string texturePath;
};
