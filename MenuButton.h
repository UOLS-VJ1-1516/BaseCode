#pragma once
#include "GameObject.h"

class MenuButton : public GameObject
{
public:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	MenuButton(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};