#include "Player.h"
#include "TextureManager.h"
#include "game.h"

Player::Player(std::string id) {
	Player::id = id;
	Player::spriteCol = 0;
	Player::spriteRow = 0;
	Player::xDirection = 0;
	Player::yDirection = 0;
	Player::speed = 0;
	Player::maxSpeed = 5;
	Player::accel = 0.001;
	Player::friction = 0;
	Player::startMove = 0;
}
Player::~Player() {
	Player::id = id;
	Player::spriteCol = 0;
	Player::spriteRow = 0;
	Player::xDirection = 0;
	Player::yDirection = 0;
	Player::speed = 0;
	Player::maxSpeed = 5;
	Player::accel = 0;
	Player::friction = 1;
	Player::startMove = 0;
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
		//VELOCITY
		float acceleration = (accel - friction);
		if (acceleration < 0) acceleration = 0;
		if (startMove == 0) startMove = SDL_GetTicks();
		speed += acceleration * (SDL_GetTicks()-startMove);
		if (speed > maxSpeed) speed = maxSpeed;
		
		//MOVEMENT
		spriteCol = (int)((SDL_GetTicks() / 120) % nCols);
		if (xDirection > 0) {
			position += Vector2(speed, 0);
			spriteRow = 2;
		} else if (xDirection < 0) {
			position -= Vector2(speed, 0);
			spriteRow = 1;
		}
		//MOVEMENT
		if (yDirection > 0) {
			position += Vector2(0, speed);
			spriteRow = 0;
		}
		else if (yDirection < 0) {
			position -= Vector2(0, speed);
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
	} else {
		startMove = 0;
		speed = 0;
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
