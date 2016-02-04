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
	void load(const LoadPar * lPar);
	~MenuButton();
	void draw(SDL_Renderer* lRender);
	void draw();
	void update();
	void clean();
	static GameObject * Create() { return new MenuButton(); }
	int getCallbackID() const { return m_callbackID; };
	void setCallback(void(*callback)()) {
		m_callback = callback;
	};

protected:
	void(*m_callback)();
	bool m_bR;
	const LoadPar * Params;
	Vector2D* pMPosition;
	int m_callbackID;
	
};