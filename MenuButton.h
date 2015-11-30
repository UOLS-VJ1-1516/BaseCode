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
	MenuButton();
	void setCallback(void(*callback)());
	void setcallbackID(int cbId)
	{
		this->callbackID = cbId;
	}
	int getcallbackID()
	{
		return callbackID;
	}
	void load(const LoaderParams* pParams);
	~MenuButton();
	void draw();
	void update();
	void clean();

	static GameObject* Create() {

		return new MenuButton();

	}

protected:
	void(*m_callback)();
	int callbackID;
	bool m_bReleased;
	const LoaderParams* Params;
	Vector2D* pMousePos;
};
