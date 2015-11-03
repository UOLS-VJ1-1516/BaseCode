#include "Player.h"
#include "TextureManager.h"
#include "Game.h"

Player::Player(){};
Player::~Player(){};

void Player::load(const LoaderParams* pParams){
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_spriteNum = pParams->getSpriteNum();
	m_currentRow = pParams->getRowNum();
	TextureManager::Instance()->load(m_fileName, m_textureID, Game::Instance()->getRenderer());
	TextureManager::Instance()->setFrame(m_textureID, m_x, m_y, m_width, m_height);
};

void Player::draw(){
	
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
};

void Player::update()
{
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
};

void Player::clean(){};