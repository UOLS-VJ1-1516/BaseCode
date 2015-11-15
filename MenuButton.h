#pragma once
#include "GameObject.h"

class MenuButton : public GameObject {
public:
	enum button_state {
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLIKED = 2
	};
	MenuButton(const LoaderParams* pParams, void(*callback)());
	void load(const LoaderParams * pParams);
	~MenuButton();
	void draw();
	void update();
	void clean();

	

protected:
	void(*m_callback)();
	bool m_bR;
	const LoaderParams * Params;
	Vector2D* pMPosition;

};