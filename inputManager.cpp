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

bool InputManager::isKeyPressed(SDL_Scancode key) {
	const Uint8 * state = SDL_GetKeyboardState(NULL);
	return (state[key]);
}

bool InputManager::isMouseButtonUp(SDL_Event e, int buttonNumber) {
	return ((e.type == SDL_MOUSEBUTTONUP) && (e.button.button == buttonNumber)) ? true : false;
}

bool InputManager::isMouseButtonDown(SDL_Event e, int buttonNumber) {
	return ((e.type == SDL_MOUSEBUTTONDOWN) && (e.button.button == buttonNumber)) ? true : false;
}

bool InputManager::isMouseButtonPressed(int buttonNumber) {
	return (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(buttonNumber)) ? true : false;
}

Vector2 InputManager::getMousePosition(SDL_Event e) {
	return Vector2(e.button.x, e.button.y);
}
