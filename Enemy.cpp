#include "game.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "Vector2D.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::draw(SDL_Renderer* pRender) {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Enemy::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_currentRow = 0;
	m_spriteNum = pParams->getSpriteNum();
}

void Enemy::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % m_spriteNum);
	m_position.setX(m_position.getX() + 1);
}

void Enemy::clean() {};