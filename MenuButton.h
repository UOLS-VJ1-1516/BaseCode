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
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual ~MenuButton() {};
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);

protected:
	void(*m_callback)();
	bool m_bReleased;
	
};