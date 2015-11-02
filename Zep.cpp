#include "TextureManager.h"
#include "Zep.h"
#include "Game.h"

Zep::Zep() {};
Zep::~Zep() {};

void Zep::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}
void Zep::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;

}
void Zep::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	
}

void Zep::clean() {
};
