#pragma once
#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include "GameObject.h"

#include "TextureManager.h"

class MenuButton : public GameObject
{
public:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	MenuButton(const LoaderParams* pParams, void(*callback)());
	~MenuButton();
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

private:
	void(*m_callback)();
	bool m_bReleased;
};
#endif