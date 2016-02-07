#pragma once
#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "Camera.h"

Enemy::Enemy() {
	m_position = Vector2D(0, 0);
};
Enemy::~Enemy() {};

void Enemy::draw()
{
	if (m_velocity.getX() < 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
	}
};

void Enemy::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_maxVelocity = pParams->getMaxSpeed();
	m_velocity.setX(pParams->getSpeedX());
	m_velocity.setY(pParams->getSpeedY());
	myvelocity = pParams->getSpeedX();
	//m_acceleration.setX(0);
	//m_acceleration.setY(0);
	m_frictionCoeficient = pParams->getFrictionCoeficient();
	m_friction = m_velocity*m_frictionCoeficient;
};

void Enemy::update() {
	m_pBoundingBox.x = m_position.getX() + m_collisionMargin;
	m_pBoundingBox.y = m_position.getY();
	m_pBoundingBox.h = m_height;
	m_pBoundingBox.w = m_width - 2 * m_collisionMargin;
	int pixelsToChangeFrame = 12;
	m_velocity = m_velocity.normalize()*myvelocity;
	m_position += m_velocity;
	m_currentFrame = ((int)m_position.getX() / pixelsToChangeFrame) % m_spriteNum;
	//if ((m_position.getX() < 0 && m_velocity.getX() < 0) || (m_position.getX() > 100 && m_velocity.getX() > 0)) {
	//	m_velocity *= -1;
	//}

	//m_acceleration.setX(0);
	//m_acceleration.setY(1);
	CollisionObject::update();
};

void Enemy::stopX(int positionX)
{
	m_position.setX(positionX);
	m_velocity.setX(m_velocity.getX()*-1);
	m_acceleration.setX(0);
}

void Enemy::stopY(int positionY)
{
	m_position.setY(positionY);
	m_velocity.setY(0);
	//m_acceleration.setY(0);
	m_friction.setY(0);
}

void Enemy::onCollision(GameObject * go)
{
}

