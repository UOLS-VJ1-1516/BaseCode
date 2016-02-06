#pragma once
#include "LoaderParams.h"
#include "GameObject.h"
#ifndef MENUBUTTON_H
#define MENUBUTTON_H

class MenuButton : public GameObject
{
public:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};
	
	MenuButton();
	~MenuButton();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
	static GameObject * Create() { return new MenuButton(); }
protected:
	void(*m_callback)();
	bool m_bReleased;
	static const std::string MenuButton::s_ButtonID;
	int m_callbackID;
	const LoaderParams *pParams;
};
#endif MENUBUTTON_H
