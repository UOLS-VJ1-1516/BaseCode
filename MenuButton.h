#pragma once
#include "GameObject.h"
#include "LoaderParams.h"

class MenuButton : public GameObject
{
public:
	enum button_state {
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		MOUSE_PRESSED = 2
	};
	MenuButton();
	virtual void load(LoaderParams* params);
	virtual ~MenuButton() {};
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void handleEvents(SDL_Event e);
	void setTexture(std::string textureID, std::string texturePath, int nCols, int nRows);
	std::string getTextureId();
	std::string getTexturePath();
protected:
	void(*callback)();
	bool bReleased;
private:
	std::string textureID;
	std::string texturePath;
	int spriteCol, spriteRow;
	int nCols, nRows;
};