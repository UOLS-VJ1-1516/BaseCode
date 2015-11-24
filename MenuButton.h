#pragma once
#include "GameObject.h"
#include "Game.h"


class MenuButton : public GameObject {


public:


	enum button_state {


		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLIKED = 2
	};



	MenuButton(const Params* pParams, void(*callback)());

	void load(const Params * pParams);
	~MenuButton();
	void draw();
	void update();
	void clean();
	void(*m_callback)();
	bool m_bR;
	const Params * Params;
	Vector2D* pMPosition;

};