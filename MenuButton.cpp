#include "MenuButton.h"
#include "TextureManager.h"
#include "game.h"
#include "inputManager.h"

MenuButton::MenuButton() {
	spriteRow = 0;
	spriteCol = 0;
}

GameObject * MenuButton::create() {
	return new MenuButton();
}

void MenuButton::load(LoaderParams * params) {
	this->position.setX((float)params->getX());
	this->position.setY((float)params->getY());
	this->width = params->getWidth();
	this->height = params->getHeight();
	//this->callback = params->f_callback; //ya no va???
	this->callbackID = params->getCallbackID(); //setcallbackid
}

void MenuButton::draw() {
	TextureManager::getInstance()->drawFrame(
		this->textureID,
		this->position.getX(),
		this->position.getY(),
		this->width,
		this->height,
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
		else spriteRow = MOUSE_PRESSED;
		if (input->isMouseButtonUp(e, SDL_BUTTON_LEFT)) {
			spriteRow = MOUSE_OVER;
			callback();
		}
	} //OUT
	else spriteRow = MOUSE_OUT;
}

void MenuButton::setTexture(std::string textureID, std::string texturePath, int nCols, int nRows) {
	this->textureID = textureID;
	this->texturePath = texturePath;
	this->nCols = nCols;
	this->nRows = nRows;
}

void MenuButton::setTexture(std::string textureID, int nCols, int nRows) {
	this->textureID = textureID;
	this->nCols = nCols;
	this->nRows = nRows;
}

std::string MenuButton::getTextureId() {
	return textureID;
}

std::string MenuButton::getTexturePath() {
	return texturePath;
}

void MenuButton::setCallback(void(*callback)()) {
	this->callback = callback;
}
