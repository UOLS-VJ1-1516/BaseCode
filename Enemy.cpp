#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
}

void Enemy::load(int x, int y, int width, int height,
	std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentFrame = 0;
	m_currentRow = 0;
	m_sprits = 0;
	m_flip = 0;
}

void Enemy::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_currentRow = pParams->getCurrentRow();
	m_sprits = pParams->getSprits();
	m_flip = pParams->getFlip();

};

void Enemy::draw(SDL_Renderer* pRender) {
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRender, m_flip);
}

void Enemy::update() {
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
}


void Enemy::clean() {}