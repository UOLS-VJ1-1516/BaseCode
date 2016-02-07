#pragma once
#include "GameObject.h"
#include "InputHandler.h"
#include "Game.h"
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

	MenuButton();
	~MenuButton();
	virtual void onCollsion(GameObject* other);

	void draw();
	void load(const LoaderParams* pParams);
	static GameObject* Create() { return new MenuButton(); };
	int getCallbackID() const { return m_callbackID; }
	void setCallback(void(*callback)()) { m_callback = callback; }
	virtual void update();
	virtual void clean();
protected:
	void(*m_callback)();
	bool m_bReleased;
	int m_callbackID;

};
