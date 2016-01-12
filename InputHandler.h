#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include "vector"
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
	// Métodos de acceso
//	void onKeyUp();
//	void onKeyDown();

	bool isKeyDown(SDL_Scancode key);
	InputHandler();

	Vector2D* m_mousePosition;
	Vector2D* GetMousePosition();
	bool getMouseButtonState(int buttonNumber);
	
	SDL_Event event;

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};
private:
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
	static InputHandler* s_pInstance;
};