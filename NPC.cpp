#include "NPC.h"
#include "TextureManager.h"
#include "game.h"

NPC::NPC() {
	NPC::spriteCol = 0;
	NPC::spriteRow = 0;
	NPC::xDirection = 1;
	NPC::yDirection = 0;
	NPC::speed = 0;
	NPC::maxSpeed = 5;
	NPC::accel = 0.001;
	NPC::friction = 0.00002;
	NPC::startMove = 0;
}
NPC::~NPC() {}

GameObject * NPC::create() {
	return new NPC();
}

void NPC::load(LoaderParams* params) {
	NPC::setId(params->getId());
	NPC::position.setX((float)params->getX());
	NPC::position.setY((float)params->getY());
	NPC::width = params->getWidth();
	NPC::height = params->getHeight();
}
void NPC::draw() {
	TextureManager::getInstance()->drawFrame(
		NPC::textureID,
		NPC::position.getX(),
		NPC::position.getY(),
		NPC::width,
		NPC::height,
		spriteRow,
		spriteCol,
		Game::getInstance()->getRenderer()
	);
}

void NPC::update() {
	spriteCol = (int)((SDL_GetTicks() / 120) % nCols);
	if (xDirection > 0) {
		spriteRow = 2;
		if (position.getX() >= (SDL_GetWindowSurface(Game::getInstance()->getWindow())->w)) {
			xDirection = -1;
		}
	} else {
		spriteRow = 1;
		if (position.getX() <= 0) xDirection = 1;
	}
	if (accel > 0) {
		float acceleration = accel - friction;
		if (acceleration < 0) acceleration = 0;
		if (startMove != 0) startMove = SDL_GetTicks();
		speed += acceleration * (SDL_GetTicks() - startMove);
		startMove = SDL_GetTicks();
		if (speed > maxSpeed) speed = maxSpeed;
		position += Vector2(speed*xDirection, speed*yDirection);
	} else {
		speed = 0;
		startMove = 0;
	}
}
void NPC::clean() {

}

void NPC::handleEvents(SDL_Event e) {
	//nothing
}

void NPC::setTexture(std::string textureID, std::string texturePath, int nCols, int nRows) {
	NPC::textureID = textureID;
	NPC::texturePath = texturePath;
	NPC::nCols = nCols;
	NPC::nRows = nRows;
}

void NPC::setTexture(std::string textureID, int nCols, int nRows) {
	this->textureID = textureID;
	this->nCols = nCols;
	this->nRows = nRows;
}

std::string NPC::getTextureId() {
	return textureID;
}

std::string NPC::getTexturePath() {
	return texturePath;
}
