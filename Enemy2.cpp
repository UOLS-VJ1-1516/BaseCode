#include "TextureManager.h"
#include "Enemy2.h"
#include "Game.h"

Enemy2::Enemy2() {
	m_velocity.setX(0.1);
	m_velocity.setY(0);
	m_frictionRight.setX(m_velocity.getX() - 0.08);
	m_frictionLeft.setX(m_velocity.getX() - 0.08);
};

Enemy2::~Enemy2() {};
SDL_RendererFlip turnEnemy2 = SDL_FLIP_NONE;

void Enemy2::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turnEnemy2);
}

void Enemy2::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;
}

void Enemy2::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	if (m_position.getX() <= 0) {	
		m_velocity.setX(0.1);
		m_velocity.setX((m_velocity.getX() - m_frictionRight.getX()));
		turnEnemy2 = SDL_FLIP_NONE;
	} else if (m_position.getX() >= 600) {
		m_velocity.setX(-0.1);
		m_velocity.setX((m_velocity.getX() + m_frictionLeft.getX()));
		turnEnemy2 = SDL_FLIP_HORIZONTAL;
	}
	GameObject::update();
}

void Enemy2::clean() {

};
