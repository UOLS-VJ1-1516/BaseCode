#include "Game.h"
#include "Bottones.h"
#include "TextureManager.h"

Bottones::Bottones() {};
Bottones::~Bottones() {};

void Bottones::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Bottones::drawR(int angle) {
	TextureManager::Instance()->draw(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Bottones::load(const LoaderParams * pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentFrame = 0;
	m_currentRow = 0;
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setX(0);
	m_acceleration.setY(0);

}

void Bottones::update() {
	int framesPS = 10;
	m_currentFrame = (int)((((Game::Instance()->getTicks())*framesPS) / 1000) % m_spriteNum);
}
void Bottones::clean() {

}