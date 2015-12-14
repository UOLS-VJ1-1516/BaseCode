#pragma once
#include "GameObject.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Vector2D.h"

//Clase que crea un game object del tipo boton
class MenuButton : public GameObject
{
public:
	MenuButton();
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void load(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	static GameObject * Create() { return new MenuButton(); }
	void setCallback(void(*callback)()) { m_callback = callback; }
	int getCallbackID() const { return m_callbackID; }

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