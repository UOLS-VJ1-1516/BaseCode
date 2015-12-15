#pragma once
#include "GameObject.h"

class MenuButton : public GameObject
{


public:


	MenuButton();


	virtual void load(const Params* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();



	static GameObject * Create() { return new MenuButton(); }

	int getCallbackID() const { return m_callbackID; }

	void setCallback(void(*callback)()) { m_callback = callback; }

    enum button_state{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};


	void(*m_callback)();
	bool m_bReleased;
};