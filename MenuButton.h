#pragma once

#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include "GameObject.h"

class MenuButton : public GameObject {
	public:
		enum button_state {
			MOUSE_OUT = 0,
			MOUSE_OVER = 1,
			CLICKED = 2
		};
		MenuButton();
		virtual void load(const LoaderParams* pParams);
		~MenuButton();
		virtual void draw();
		virtual void update();
		virtual void clean();
		virtual void onCollision(GameObject* other);
		static GameObject* Create() { return new MenuButton(); }

		int getCallbackID() const { return m_callbackID; }
		void setCallback(void(*callback)()) { m_callback = callback; }

	private:
		void(*m_callback)();
		bool m_bReleased;
		int m_callbackID;
};

#endif