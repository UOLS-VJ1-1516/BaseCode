#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "InputHandler.h"
#include "algorithm"
	Player::Player(){
		m_position.setX(0);
		m_position.setY(0);
		m_velocity.setX(0);
		m_velocity.setY(0);
		m_maxVelocity.setX(5);
		m_acceleration.setX(0.5);
		m_friction.setX(-0.3);
	}
	Player::~Player()
	{
	}

	void Player::draw()
	{
		TextureManager::Instance()->drawFrame( m_textureID, (int)m_position.getX(), (int)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flip);
	}
	void Player::load(const LoaderParams *pParams) {
		GameObject::load(pParams);

	}
	void Player::update() {
		m_currentFrame = (int)((SDL_GetTicks() / 100) % m_numsprites);

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
		}
		else {
			// in case of no key press, stay quiet.
			if (m_velocity.getX() == 0) {
				m_currentFrame = 7;
			}
			if(m_velocity.getX() > 0)
				m_velocity.setX(std::max(m_velocity.getX() + m_friction.getX(),(float)0));
			else if (m_velocity.getX() < 0)
				m_velocity.setX(std::min(m_velocity.getX() - m_friction.getX(), (float)0));
		}
		// block the sprite to go outside de screen
		if (m_position.getX() > 750)
		{
			m_position.setX(750);
		}
		else if (m_position.getX() < 0) {
			m_position.setX(0);
		}
		GameObject::update();
	}
	void Player::clean() {
	}