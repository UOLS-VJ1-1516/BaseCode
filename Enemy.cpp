#include "Enemy.h"
#include "TextureManager.h"
#include "game.h"
#include "Camera.h"

Enemy::Enemy() {

}
Enemy::~Enemy() {

}

void Enemy::load(const LoaderParams* pParams) {
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_textureID = pParams->getTextureID();
	m_numSprite = pParams->getNumSprite();
	m_velocity.setX(pParams->getSpeedX());
	m_velocity.setY(pParams->getSpeedY());
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_maxVelocity = pParams->getMaxSpeed();
	m_frictionCo = pParams->getFrictionCo();
	m_friction = m_velocity*m_frictionCo;
}

void Enemy::draw() {
	//Si la velocidad es negativa, el sprite mira hacia la izquierda
	if (m_velocity.getX() > 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
	//Si la velocidad es positiva, el sprite mira hacia la derecha
	else if (m_velocity.getX() < 0) {
		//refresh img
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
	}
}

void Enemy::update() {
	if (m_position.getX() < 0 && m_velocity.getX() < 0) {
		m_velocity *= -1;
	}
	if (m_position.getX() > (Game::Instance()->getWindowWidth() - m_width) && m_velocity.getX() > 0) {
		m_velocity *= -1;
	}
	m_position += m_velocity;
	m_currentFrame = ((Game::Instance()->getTicks() / 100) % m_numSprite);
}

void Enemy::clean() {

}

void Enemy::onCollision(GameObject * other) {

}