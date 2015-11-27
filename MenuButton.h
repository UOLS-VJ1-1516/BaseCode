#pragma once
#include "GameObject.h"


class MenuButton : public GameObject {
public:
	enum button_state {
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLIKED = 2
	};
	MenuButton();
	
	//MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void load(const LoaderParams * pParams);
	~MenuButton() {};
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new MenuButton(); }
	
	virtual void setCallbacks(void(*callback)()) { m_callback = callback; };
	virtual int getCallbackID() { return m_callbackID; };

	
	
protected:
	void(*m_callback)();
	bool m_bR;
	const LoaderParams * pParams;
	Vector2D* pMPosition;
	void setCallback(void(*callback)()) { m_callback = callback; }

};