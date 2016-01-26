#pragma once
#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "InputHandler.h"
#include "algorithm"
#include "Camera.h"

Player::Player() {
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setX(5);
	m_maxVelocity.setY(5);
	m_acceleration.setX(0.5);
	m_acceleration.setY(0.5);
	m_friction.setX(-0.3);
	m_friction.setY(0);
}
Player::~Player()
{
}

void Player::draw()
{
	TextureManager::Instance()->drawFrame( m_textureID, (int)m_position.getX()-Camera::Instance()->getPosition().m_x, (int)m_position.getY(),
		m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flip);
}
void Player::load(const LoaderParams *pParams) {
	//CollisionObject::load(pParams);
	GameObject::load(pParams);
}
void Player::update() {
	m_acceleration.setY(10);
	m_currentRow = 0;

	m_currentFrame = (int)((SDL_GetTicks() / 100) % 8);

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		flip = SDL_FLIP_HORIZONTAL;
		m_velocity.setX(m_velocity.getX() + std::max(m_acceleration.getX() + m_friction.getX(), (float) 0));

		if (m_velocity.getX() >= m_maxVelocity.getX())
			m_velocity.setX(m_maxVelocity.getX());
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		flip = SDL_FLIP_NONE;
		m_velocity.setX(m_velocity.getX() - std::max(m_acceleration.getX() + m_friction.getX(), (float)0));
		if (m_velocity.getX() <= -m_maxVelocity.getX())
			m_velocity.setX(-m_maxVelocity.getX());
	}else {
		// in case of no key press, stay quiet.
		if (m_velocity.getX() == 0) {
			m_currentFrame = (int)((SDL_GetTicks() / 200) % 4);
			m_currentRow = 1;
		}
		if (m_velocity.getX() > 0) {
			m_velocity.setX(std::max(m_velocity.getX() + m_friction.getX(),(float)0));
		}
		else if (m_velocity.getX() < 0) {
			m_velocity.setX(std::min(m_velocity.getX() - m_friction.getX(), (float)0));
		}
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		maxJump += 0.1;
		if (maxJump < 1.5)
		{
			m_currentRow = 6;
			m_currentFrame = 0;
			m_acceleration.setY(-10);
		}
	}
	// block the sprite to go outside de screen
	if (m_position.getX() > 1920-m_width)
	{
		m_position.setX(Game::Instance()->getVisibleWidth() - m_width);
	}
	else if (m_position.getX() < 0) {
		m_position.setX(0);
	}else if (m_position.getY() > Game::Instance()->getVisibleHeight() - m_height)
	{
		//
		m_position.setY(Game::Instance()->getVisibleHeight()-m_height);
	}
	else if (m_position.getY() < 0) {
		m_position.setY(0);
	}

	CollisionObject::update();
	Camera::Instance()->setPosition(m_position);
}
void Player::clean() {
}