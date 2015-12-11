#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "inputManager.h"
#include <iostream>

using namespace std;

#define UP SDL_SCANCODE_W
#define DOWN SDL_SCANCODE_S
#define RIGHT SDL_SCANCODE_D
#define LEFT SDL_SCANCODE_A

Player::Player() {
	this->spriteCol = 0;
	this->spriteRow = 0;
	this->xDirection = 0;
	this->yDirection = 0;
	this->speed = 0;
	this->maxSpeed = 5;
	this->accel = 0.01;
	this->friction = 0.005;
	this->startMove = 0;
}

Player::~Player() {
}

GameObject * Player::create() {
	return new Player();
}

void Player::load(LoaderParams* params) {
	this->setId(params->getId());
	this->position.setX((float)params->getX());
	this->position.setY((float)params->getY());
	this->width = params->getWidth();
	this->height = params->getHeight();
}
void Player::draw() {
	TextureManager::getInstance()->drawFrame(
		this->textureID,
		this->position.getX(),
		this->position.getY(),
		this->width,
		this->height,
		this->spriteRow,
		this->spriteCol,
		Game::getInstance()->getRenderer()
	);
}

void Player::update() {

	//SET SPEED
	if (xDirection != 0 || yDirection != 0) {
		//ACCELERATION
		if (startMove == 0) startMove = SDL_GetTicks();
		speed += (accel - friction) * (SDL_GetTicks() - startMove);
		startMove = SDL_GetTicks();
		if (speed > maxSpeed) speed = maxSpeed;
	} else {
		//DECELERATION
		if (startMove == 0) startMove = SDL_GetTicks();
		speed -= friction * (SDL_GetTicks() - startMove);
		startMove = SDL_GetTicks();
		if (speed < 0.0f) speed = 0.0f;
		else if (speed == 0.0f) startMove = 0.0f;
	}

	if (speed != 0) {
		//MOVEMENT X
		spriteCol = (int)((SDL_GetTicks() / 120) % nCols);
		if (xDirection > 0) {
			position += Vector2(speed, 0);
			spriteRow = 2;
		}
		else if (xDirection < 0) {
			position -= Vector2(speed, 0);
			spriteRow = 1;
		}
		//MOVEMENT Y
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
			position.setX(SDL_GetWindowSurface(Game::getInstance()->getWindow())->w - (width / 2));
		if (position.getX() < (width / 2))
			position.setX((width / 2));
		if (position.getY() + (height / 2) > (SDL_GetWindowSurface(Game::getInstance()->getWindow())->h))
			position.setY(SDL_GetWindowSurface(Game::getInstance()->getWindow())->h - (height / 2));
		if (position.getY() < (height / 2))
			position.setY((height / 2));
	} else spriteCol = 0;
}

void Player::handleEvents(SDL_Event e) {
	InputManager* input = InputManager::getInstance();
	//X AXIS
	if (input->isKeyPressed(LEFT) || input->isKeyPressed(RIGHT)) {
		if (input->isKeyPressed(LEFT)) xDirection = -1;
		if (input->isKeyPressed(RIGHT)) xDirection = 1;
	} else xDirection = 0;

	//Y AXIS
	if (input->isKeyPressed(DOWN) || input->isKeyPressed(UP)) {
		if (input->isKeyPressed(DOWN)) yDirection = 1;
		if (input->isKeyPressed(UP)) yDirection = -1;
	} else yDirection = 0;
}

void Player::clean() {

}

void Player::setTexture(std::string textureID, std::string texturePath, int nCols, int nRows) {
	this->textureID = textureID;
	this->texturePath = texturePath;
	this->nCols = nCols;
	this->nRows = nRows;
}

void Player::setTexture(std::string textureID, int nCols, int nRows) {
	this->textureID = textureID;
	this->nCols = nCols;
	this->nRows = nRows;
}

std::string Player::getTextureId() {
	return textureID;
}

std::string Player::getTexturePath() {
	return texturePath;
}