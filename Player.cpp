#include "TextureManager.h"
#include "Player.h"
#include "Game.h"

//Player::Player() {};
//Player::~Player() {};
	void Player::draw()
	{
		/*GameObject::draw();
		spriteNum = (int)((SDL_GetTicks() / 100) % 10);*/
		TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
	void Player::load(const LoaderParams* pParams)
	{
		m_width = pParams->getWidth();
		m_height = pParams->getHeight();
		m_x = pParams->getX();
		m_y = pParams->getY();
		m_textureID = pParams->getTextureID();
		spriteNum = pParams->getNum();
		m_currentRow = 0;
		
	};
	void Player::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % spriteNum);
};

void Player::clean() {
};
