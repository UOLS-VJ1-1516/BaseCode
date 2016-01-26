#pragma once
#include "game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"
#include "SoundManager.h"


Player::Player() {	
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_maxVelocity.m_x = 10;
	m_maxVelocity.m_y = 10;
	m_minVelocity.m_x = -10;
	m_minVelocity.m_y = -10;
	m_acceleration.m_x = 0;
	m_acceleration.m_y = 0;
	m_friction.m_x = 0;
	m_friction.m_y = 0;
	maxJump = 1;
};
Player::~Player() {};

void Player::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), flip);
}

void Player::load(const LoaderParams* pParams) {
	GameObject::load(pParams);
}

void Player::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % m_spriteNum);

	m_acceleration.m_y = 10;

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_acceleration.m_x = 2;
		flip = SDL_FLIP_HORIZONTAL;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_acceleration.m_x = -2;
		flip = SDL_FLIP_NONE;
	}
	else {
		m_currentFrame = int((SDL_GetTicks() / 100) % 1);
		m_velocity.m_x = 0;
		m_acceleration.m_x = 0;
	 }	

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		SoundManager::Instance()->playSound("soundJump", 0);
		maxJump += 3;
		if (maxJump < 10) {
			m_acceleration.m_y = -10;
		}
	}	
	
	CollisionObject::update();	
}

void Player::clean() {};