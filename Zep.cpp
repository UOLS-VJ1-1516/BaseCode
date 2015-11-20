#include "TextureManager.h"
#include "Zep.h"
#include "Game.h"

Zep::Zep() {
	m_velocity.setX(0.1);
	m_velocity.setY(0);
	m_frictionRight.setX(m_velocity.getX() - 0.08);
	m_frictionLeft.setX(m_velocity.getX() - 0.08);
};
Zep::~Zep() {};
SDL_RendererFlip turnZep = SDL_FLIP_HORIZONTAL;

void Zep::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID,(int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turnZep);
}
void Zep::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;

}
void Zep::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	if (m_position.getX() <= 0) {
		m_velocity.setX(0.1);
		m_velocity.setX((m_velocity.getX() - m_frictionRight.getX()));
		turnZep = SDL_FLIP_HORIZONTAL;
	}

	else if (m_position.getX() >= 550) {
		m_velocity.setX(-0.1);
		m_velocity.setX((m_velocity.getX() + m_frictionLeft.getX()));
		turnZep = SDL_FLIP_NONE;


	}
	GameObject::update();


}

void Zep::clean() {
};
