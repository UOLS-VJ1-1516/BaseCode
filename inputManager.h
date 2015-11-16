#pragma once
#include "SDL.h"
#include "Vector2.h"

class InputManager
{
public:
	static InputManager* getInstance() {
		if (instance == 0)
			instance = new InputManager();
		return instance;
	}
	~InputManager() {};
	//void update();
	//void clean();
	// Métodos de acceso
	bool isKeyDown(SDL_Event e, SDL_Scancode key);
	bool isKeyUp(SDL_Event e, SDL_Scancode key);
	bool getMouseButtonState(SDL_Event e, int buttonNumber);
	Vector2 getMousePosition(SDL_Event e);
private:
	InputManager();
	static InputManager* instance;
};
