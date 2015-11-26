#include "MenuButton.h"
#include "TextureManager.h"
#include "game.h"
#include "inputManager.h"

MenuButton::MenuButton() {
	spriteRow = 0;
	spriteCol = 0;
}

void MenuButton::load(LoaderParams * params) {
	MenuButton::position.setX((float)params->getX());
	MenuButton::position.setY((float)params->getY());
	MenuButton::width = params->getWidth();
	MenuButton::height = params->getHeight();
	MenuButton::callback = params->f_callback;
}

void MenuButton::draw() {
	TextureManager::getInstance()->drawFrame(
		MenuButton::textureID,
		MenuButton::position.getX(),
		MenuButton::position.getY(),
		MenuButton::width,
		MenuButton::height,
		spriteRow,
		spriteCol,
		Game::getInstance()->getRenderer()
	);
}

void MenuButton::update() {

}

void MenuButton::clean() {
}

void MenuButton::handleEvents(SDL_Event e) {
	InputManager* input = InputManager::getInstance();
	Vector2 mousePos = input->getMousePosition(e);

	if (mousePos.getX() >= this->position.getX() - (this->width / 2)
		&& mousePos.getX() <= this->position.getX() + (this->width / 2)
		&& mousePos.getY() >= this->position.getY() - (this->height / 2)
		&& mousePos.getY() <= this->position.getY() + (this->height / 2)) {
		//HOVER
		if (!input->isMouseButtonPressed(SDL_BUTTON_LEFT)) spriteRow = MOUSE_OVER;
		else if (input->isMouseButtonPressed(SDL_BUTTON_LEFT)) spriteRow = MOUSE_PRESSED;
		if (input->isMouseButtonUp(e, SDL_BUTTON_LEFT)) {
			spriteRow = MOUSE_OVER;
			callback();
		}
	} //OUT
	else spriteRow = MOUSE_OUT;
}

void MenuButton::setTexture(std::string textureID, std::string texturePath, int nCols, int nRows) {
	MenuButton::textureID = textureID;
	MenuButton::texturePath = texturePath;
	MenuButton::nCols = nCols;
	MenuButton::nRows = nRows;
}

std::string MenuButton::getTextureId() {
	return textureID;
}

std::string MenuButton::getTexturePath() {
	return texturePath;
}
