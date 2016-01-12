#pragma once
#include "GameObject.h"
#include "LoaderParams.h"

class MenuButton : public GameObject
{
public:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	MenuButton();
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual ~MenuButton() {};
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new MenuButton(); }
	virtual void load(const LoaderParams* pParams);
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() { return m_callbackID; }
protected:
	void(*m_callback)();
	bool m_bReleased;
	
};