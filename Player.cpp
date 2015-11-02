#include "Player.h"
#include "TextureManager.h"
#include "game.h"
	Player::Player(){
	}

	Player::~Player()
	{
	}

	void Player::draw()
	{
		TextureManager::Instance()->drawFrame( m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
	}
	void Player::load(const LoaderParams *pParams) {
		m_x = pParams->getX();
		m_y = pParams->getY();

		m_width = pParams->getWidth();
		m_height = pParams->getHeight();

		m_textureID = pParams->getTextureID();
		m_numsprites = pParams->getNumSprites();
		m_currentFrame = 0;
		m_currentRow = 0;

	}
	void Player::update() {
		m_currentFrame = (int)((SDL_GetTicks() / 100) % m_numsprites);
	}
	void Player::clean() {
	}