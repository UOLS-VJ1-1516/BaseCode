#pragma once
#include "GameObject.h"
#include "InputHandler.h"
#include "texturemanager.h"
#include "game.h"


class MenuButton : public GameObject
{

public:

	MenuButton(void(*callback)());
	void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

private:

	void(*m_callback)();
	bool m_bReleased;
	const LoaderParams* Params;
	Vector2D* pMousePos;

};