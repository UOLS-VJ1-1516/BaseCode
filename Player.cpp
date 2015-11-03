#include "Player.h"
#include "TextureManager.h"
#include "game.h"

Player::Player(std::string id) {
	Player::id = id;
	Player::spriteCol = 0;
	Player::spriteRow = 0;
}
Player::~Player() {}

void Player::load(LoaderParams* params) {
	Player::x = (float)params->getX();
	Player::y = (float)params->getY();
	Player::width = params->getWidth();
	Player::height = params->getHeight();
}
void Player::draw() {
	TextureManager::getInstance()->drawFrame(
		Player::textureID,
		Player::x,
		Player::y,
		Player::width,
		Player::height,
		spriteRow,
		spriteCol,
		Game::getInstance()->getRenderer()
	);
}

void Player::update() {
	spriteCol = (int)((SDL_GetTicks() / 120) % nCols);
	spriteRow = (int)((SDL_GetTicks() / 120) % nRows);
	if (y > (SDL_GetWindowSurface(Game::getInstance()->getWindow())->h)) {
		y = -height;
	} else {
		y++;
	}
}
void Player::clean() {

}

void Player::setTexture(std::string textureID, std::string texturePath, int nCols, int nRows) {
	Player::textureID = textureID;
	Player::texturePath = texturePath;
	Player::nCols = nCols;
	Player::nRows = nRows;
}

std::string Player::getTextureId() {
	return textureID;
}

std::string Player::getTexturePath() {
	return texturePath;
}
