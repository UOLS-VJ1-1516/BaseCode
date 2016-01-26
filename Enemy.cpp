#pragma once
#include "game.h"
#include "Enemy.h"
#include "TextureManager.h"
#include "Vector2D.h"

Enemy::Enemy() { 
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_maxVelocity.m_x = 10;
	m_maxVelocity.m_y = 10;
	m_minVelocity.m_x = -10;
	m_minVelocity.m_y = -10;
	m_acceleration.m_x = 1;
	m_acceleration.m_y = 0;
	m_friction.m_x = 0;
	m_friction.m_y = 0;
};
Enemy::~Enemy() {};

void Enemy::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), flip);
}

void Enemy::load(const LoaderParams* pParams) {
	GameObject::load(pParams);
}

void Enemy::update() {
	m_currentFrame = int((SDL_GetTicks() / 100) % m_spriteNum);
	m_acceleration.m_y = 5;

	if (!isCollisionWithTile(m_position)) {
		m_velocity.setX(speed);
		m_velocity.setY(m_velocity.getY());
	}
	else { //Si colisionan que cambie el simbolo de la velocidad
		m_velocity.setY(0);
		m_velocity.m_x = m_velocity.m_x * -1;
	}

	if (m_velocity.m_x > 0) {
		flip = SDL_FLIP_NONE;
	}
	else {
		flip = SDL_FLIP_HORIZONTAL;
	}

	CollisionObject::update();
}

void Enemy::clean() {};