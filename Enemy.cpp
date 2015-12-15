#include "Enemy.h"


Enemy::Enemy() {


	m_velocity.setX(5);
	m_velocity.setY(0);
	m_maxVelocity.setX(10);
	m_acceleration.setX(m_velocity.getX() + 0.02);
	m_friction.setX(m_velocity.getX() - 0.08);


};


Enemy::~Enemy() {



};

SDL_RendererFlip flipEnemy = SDL_FLIP_NONE;


void Enemy::load(const Params* pParams) {
	GameObject::load(pParams);
};


void Enemy::draw() {


	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};


void Enemy::update() {


	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);


	if (m_position.getX() <= 0) {


		m_velocity.setX(5);
		m_flip = SDL_FLIP_NONE;


	}else if (m_position.getX() >= Game::Instance()->getScreenWidth() - m_width) {
		m_velocity.setX(-5);
		m_flip = SDL_FLIP_HORIZONTAL;


}


	m_position += m_velocity;



};


void Enemy::clean() {



};