#include "inputManager.h"

InputManager * InputManager::instance = 0;

InputManager::InputManager() {}

bool InputManager::isKeyDown(SDL_Event e, SDL_Scancode key) {
	if (e.key.keysym.scancode == key && e.type == SDL_KEYDOWN)
		return true;
	return false;
}

bool InputManager::isKeyUp(SDL_Event e, SDL_Scancode key) {
	if (e.key.keysym.scancode == key && e.type == SDL_KEYUP)
		return true;
	return false;
}

bool InputManager::getMouseButtonState(SDL_Event e, int buttonNumber) {
	return false;
}

Vector2 InputManager::getMousePosition(SDL_Event e) {
	return Vector2();
}
