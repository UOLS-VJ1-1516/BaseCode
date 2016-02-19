#pragma once
#include "Enemy.h"
#include "TextureManager.h"
#include "game.h"
#include "Camera.h"

Vector2D m_originalVelocity;
Enemy::Enemy(): CollisionObject(){
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setX(5);
	m_maxVelocity.setY(5);
	m_acceleration.setX(0.5);
	collision = false;
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, 
		(int)m_position.getX()-Camera::Instance()->getPosition().m_x, (int)m_position.getY(),
		m_width, m_height, 
		m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flip);
}
void Enemy::load(const LoaderParams *pParams) {
	GameObject::load(pParams);
	m_originalVelocity.setX(m_velocity.getX());
}
void Enemy::update() {

	m_velocity.setY(5);
	
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_numsprites);
	if (isCollision())
	{
		if (m_velocity.getX() <= 0) {
			
			if (flip == SDL_FLIP_NONE) {
				m_velocity.setX(-m_originalVelocity.getX());
				flip = SDL_FLIP_HORIZONTAL;
				m_position.setX(m_position.getX() + 2);
			}
			else {
				m_velocity.setX(m_originalVelocity.getX());
				flip = SDL_FLIP_NONE;
				m_position.setX(m_position.getX() - 2);
			}
		}
		collision = false;
	}

	CollisionObject::update();
}
void Enemy::clean() {
}