#include "Player.h"
#include "TextureManager.h"
#include "game.h"

Player::Player() {

}
Player::~Player() {

}

void Player::load(const LoaderParams* pParams) {
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_currentRow = 0;
	m_textureID = pParams->getTextureID();
	m_numSprite = pParams->getNumSprite();
}

void Player::draw() {
	//refresh img
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void Player::update() {
	m_currentFrame = ((Game::Instance()->getTicks() / 100) % m_numSprite);
}

void Player::clean() {

}