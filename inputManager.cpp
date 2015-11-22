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

bool InputManager::getMouseButtonStateUp(SDL_Event e, int buttonNumber) {
	return ((e.type == SDL_MOUSEBUTTONUP) && (e.button.button == buttonNumber)) ? true : false;
}

bool InputManager::getMouseButtonStateDown(SDL_Event e, int buttonNumber) {
	return ((e.type == SDL_MOUSEBUTTONDOWN) && (e.button.button == buttonNumber)) ? true : false;
}

Vector2 InputManager::getMousePosition(SDL_Event e) {
	return Vector2(e.button.x, e.button.y);
}
