#include "game.h"
#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::draw(SDL_Renderer* pRender) {
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Enemy::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_currentRow = 0;
	m_spriteNum = pParams->getSpriteNum();
}

void Enemy::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % m_spriteNum);
}

void Enemy::clean() {};