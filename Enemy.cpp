#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "InputHandler.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::load(const LoaderParams* pParams)
{
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = 0;
	m_sprite = pParams->getSprits();
	//m_currentFrame = 0;
}

void Enemy::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);

}

void Enemy::update() {

	m_currentFrame = (int)((Game::Instance()->getP() / 100) % m_sprite);

	m_position.setX(m_position.getX() - 2);

}


void Enemy::clean() {};