#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "InputHandler.h"
	Player::Player(){
		m_position.setX(0);
		m_position.setY(0);
		m_velocity.setX(0);
		m_velocity.setY(0);
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
			m_velocity.setX(2);
		}
		else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		{
			m_velocity.setX(-2);
			flip = SDL_FLIP_NONE;
		}
		else {
			// in case of no key press, stay.
			m_velocity.setX(0);
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