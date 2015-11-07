#include "Player.h"
#include "TextureManager.h"
#include "game.h"

Player::Player(std::string id) {
	Player::id = id;
	Player::spriteCol = 0;
	Player::spriteRow = 0;
	Player::xDirection = 0;
	Player::yDirection = 0;
	Player::xVel = 1;
	Player::yVel = 1;
}
Player::~Player() {
	Player::id = id;
	Player::spriteCol = 0;
	Player::spriteRow = 0;
	Player::xDirection = 0;
	Player::yDirection = 0;
	Player::xVel = 1;
	Player::yVel = 1;
}

void Player::load(LoaderParams* params) {
	Player::position.setX((float)params->getX());
	Player::position.setY((float)params->getY());
	Player::width = params->getWidth();
	Player::height = params->getHeight();
}
void Player::draw() {
	TextureManager::getInstance()->drawFrame(
		Player::textureID,
		Player::position.getX(),
		Player::position.getY(),
		Player::width,
		Player::height,
		spriteRow,
		spriteCol,
		Game::getInstance()->getRenderer()
	);
}

void Player::update() {
	
	if (xDirection != 0 || yDirection != 0) {
		spriteCol = (int)((SDL_GetTicks() / 120) % nCols);
		//MOVEMENT
		if (xDirection > 0) {
			position += Vector2(xVel, 0);
			spriteRow = 2;
		} else if (xDirection < 0) {
			position -= Vector2(xVel, 0);
			spriteRow = 1;
		}
		//MOVEMENT
		if (yDirection > 0) {
			position += Vector2(0, yVel);
			spriteRow = 0;
		}
		else if (yDirection < 0) {
			position -= Vector2(0, yVel);
			spriteRow = 3;
		}
		//FIX POSITION
		if (position.getX() + (width / 2) >(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w))
			position.setX(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w - (width/2));
		if (position.getX() < (width / 2))
			position.setX((width / 2));
		if (position.getY() + (height / 2) > (SDL_GetWindowSurface(Game::getInstance()->getWindow())->h))
			position.setY(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h - (height/2));
		if (position.getY() < (height / 2))
			position.setY((height / 2));
	}
}

void Player::handleEvents(SDL_Event e) {
	//W
	if (e.key.keysym.scancode == SDL_SCANCODE_W) {
		if (e.type == SDL_KEYDOWN)
			yDirection = -1;
		else
			yDirection = 0;
	}
	//A
	if (e.key.keysym.scancode == SDL_SCANCODE_A) {
		if (e.type == SDL_KEYDOWN)
			xDirection = -1;
		else
			xDirection = 0;
	}
	//S
	if (e.key.keysym.scancode == SDL_SCANCODE_S) {
		if (e.type == SDL_KEYDOWN)
			yDirection = 1;
		else
			yDirection = 0;
	}
	//D
	if (e.key.keysym.scancode == SDL_SCANCODE_D) {
		if (e.type == SDL_KEYDOWN)
			xDirection = 1;
		else
			xDirection = 0;
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
