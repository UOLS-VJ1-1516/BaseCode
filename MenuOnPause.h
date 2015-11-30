#pragma once
#include "GameObject.h"
#include "InputHandler.h"
#include "Game.h"
#include "TextureManager.h"

class MenuOnPause : public GameObject
{
public:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	MenuOnPause(void(*callback)());
	~MenuOnPause();

	void draw();
	void load(const LoaderParams* pParams);
	virtual void update();
	virtual void clean();
protected:
	void(*m_callback)();
	bool m_bReleased;

};
