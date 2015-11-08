#pragma once
#include "Enemy.h"
#include "TextureManager.h"
#include "game.h"

int velocity = -2;
Enemy::Enemy(): GameObject(){
	m_position.setX(0);
	m_position.setY(0);
	m_velocity.setX(velocity);
	m_velocity.setY(0);
}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, 
		(int)m_position.getX(), (int)m_position.getY(), 
		m_width, m_height, 
		m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), flip);
}
void Enemy::load(const LoaderParams *pParams) {
	GameObject::load(pParams);

}
void Enemy::update() {
	//m_position.setX(m_position.getX() + 1);
	//m_position.setY(m_position.getY() + 1);
//	m_velocity.setX(1);
	GameObject::update();
//	printf("Position %d \n", m_position);
//	printf("Velocity %d \n", m_velocity);
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_numsprites);
	if (m_position.getX() >= 800)
	{
		m_velocity.setX(velocity);
		flip = SDL_FLIP_NONE;
	}
	else if (m_position.getX() <= 0) {
		m_velocity.setX(-velocity);
		flip = SDL_FLIP_HORIZONTAL;
	}
}
void Enemy::clean() {
}

