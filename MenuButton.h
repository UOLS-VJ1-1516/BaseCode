#pragma once
#include "GameObject.h"
#include <vector>
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
	virtual ~MenuButton() {};
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
		
	int getCallbackID() const { return m_callbackID; }
	void setCallbacks(void(*callback)()) { m_callback = callback; }

	static GameObject* Create() { return new MenuButton(); }

protected:
	void(*m_callback)();
	bool m_bReleased;
	int m_callbackID;
	GameObject* b;
	std::vector<GameObject*> m_gameObjects;
};