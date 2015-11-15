#pragma once
#include "GameObject.h"

class MenuButton : public GameObject
{
	public:
		MenuButton(const LoaderParams* pParams, void(*callback)());
		virtual void load(const LoaderParams* pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();
	private:
		enum button_state
		{
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};
		void(*m_callback)();
		bool m_bReleased;
};