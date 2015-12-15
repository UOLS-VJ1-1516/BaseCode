#pragma once
#include "game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Vector2D.h"


Player::Player() {
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setX(10);
	m_acceleration.setX(m_velocity.getX() + 0.1);
	m_friction.setX(m_velocity.getX() - 0.5);
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

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && (m_position.getX() < 600)) {
		m_acceleration.setX(m_acceleration.getX() + 0.1);
		m_velocity.setX(m_velocity.getX() + (m_acceleration.getX() - m_friction.getX()));
		if (m_velocity.getX() >= m_maxVelocity.getX()) {
			m_velocity.setX(m_maxVelocity.getX());
		}
		m_position += m_velocity;
		flip = SDL_FLIP_HORIZONTAL;
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT) && (m_position.getX() > 0)) {
		m_acceleration.setX(m_acceleration.getX() + 0.1);
		m_velocity.setX(m_velocity.getX() + (m_acceleration.getX() - m_friction.getX()));
		if (m_velocity.getX() >= m_maxVelocity.getX()) {
			m_velocity.setX(m_maxVelocity.getX());
		}
		m_position -= m_velocity;
			flip = SDL_FLIP_NONE;
		}	
	else {
		m_currentFrame = int((SDL_GetTicks() / 100) % 1);
		m_velocity.setX(0);
		m_acceleration.setX(0);
	 }	
	
	if (m_position.getX() >= 600) {
		m_velocity.setX(0);
	}
	else if (m_position.getX() <= 0) {
		m_velocity.setX(0);
	} 
	
}

void Player::clean() {};