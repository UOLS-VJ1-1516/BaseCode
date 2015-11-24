#include "TextureManager.h"
#include "Enemy.h"
#include "Game.h"

Enemy::Enemy() {
	m_velocity.setX(0.1);
	m_velocity.setY(0);
	m_frictionRight.setX(m_velocity.getX() - 0.08);
	m_frictionLeft.setX(m_velocity.getX() - 0.08);
};

Enemy::~Enemy() {

};
SDL_RendererFlip turnEnemy = SDL_FLIP_HORIZONTAL;

void Enemy::draw() {
	TextureManager::Instance()->drawFrame(m_textureID,(int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turnEnemy);
}

void Enemy::load(const Params* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;
}

void Enemy::update() {

	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	if (m_position.getX() <= 0) {
		m_velocity.setX(0.1);
		m_velocity.setX((m_velocity.getX() - m_frictionRight.getX()));
		turnEnemy = SDL_FLIP_HORIZONTAL;
	} else if (m_position.getX() >= 1700) {
		m_velocity.setX(-0.1);
		m_velocity.setX((m_velocity.getX() + m_frictionLeft.getX()));
		turnEnemy = SDL_FLIP_NONE;
	}

	GameObject::update();
}

void Enemy::clean() {

};
