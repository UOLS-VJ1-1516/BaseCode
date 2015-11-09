#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy() {};
Enemy::~Enemy() {};

void Enemy::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_currentRow = pParams->getCurrentRow();
	m_sprits = pParams->getSprits();
	m_flip = pParams->getFlip();
	m_position = pParams->getPosition();
	m_velocity = pParams->getVelocity();
	m_maxVelocity = pParams->getMaxVelocity();
	m_acceleration = pParams->getAcceleration();
	m_friction = pParams->getFriction();
	stateFlip = true;
};

void Enemy::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (&m_position)->getX(), (&m_position)->getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};

void Enemy::update() {
	
	if (!stateFlip) {
		m_position -= (m_velocity);
		m_flip = 1;
		if (0 >= m_position.getX()) stateFlip = true;
	} 	
	if (stateFlip) {
		if (Game::Instance()->getwidthWindow() <= m_position.getX() + m_width) stateFlip = false;
		m_position += (m_velocity);
		m_flip = 0;
		
	}
	
	m_currentFrame = (int)((Game::Instance()->getTicks() / 100) % m_sprits);
};

void Enemy::clean() {};

