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
	m_currentRow = 1;
	m_sprite = pParams->getSprits();
	m_currentFrame = 1;
	m_velocity.setX(0);
	m_velocity.setY(0);

}

void Enemy::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	/*
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) { m_velocity.setX(2); }
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) { m_velocity.setX(-2); }
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) { m_velocity.setY(-2); }
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) { m_velocity.setY(2); }
	*/

}

void Enemy::update() {
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);

	m_currentFrame = (int)((Game::Instance()->getP() / 100) % m_sprite);

	m_acceleration.setX(1);

	m_velocity += m_acceleration;
	m_position += m_velocity;
}


void Enemy::clean() {};