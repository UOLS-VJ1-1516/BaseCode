#pragma once
#include "SDL.h"
#include "vector"
#include "Vector2D.h"
class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	~InputHandler();
	void update();
	void clean();
	// M�todos de acceso
	//	void onKeyUp();
	//	void onKeyDown();
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D * getMousePosition();
	InputHandler();
	
private:
	const Uint8* m_keystate;
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mPosition;
	bool m_exitClik;
	static InputHandler* s_pInstance;

};
enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};