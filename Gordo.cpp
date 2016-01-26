#include "TextureManager.h"
#include "Gordo.h"
#include "Game.h"
#include "Camera.h"

Gordo::Gordo() {
	m_velocity.setX(0.5);
	m_velocity.setY(0);
	m_frictionRight.setX(m_velocity.getX() - 0.08);
	m_frictionLeft.setX(m_velocity.getX() - 0.08);

};
Gordo::~Gordo() {};
SDL_RendererFlip turnGordo = SDL_FLIP_NONE;
void Gordo::draw()
{
	Vector2D cameraPos = Camera::Instance()->getPosition();
	Vector2D posX;
	Vector2D posY;
	posX = m_position - cameraPos;
	TextureManager::Instance()->drawFrame(m_textureID, posX.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turnGordo);
}
void Gordo::load(const LoaderParams* pParams)
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
void Gordo::update() {
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);
	if (m_position.getX() <= 0) {
		
		m_velocity.setX(0.8);
		//m_velocity.setX((m_velocity.getX() - m_frictionRight.getX()));
		turnGordo = SDL_FLIP_NONE;
	}

	else if (m_position.getX() >= 700) {
		m_velocity.setX(-0.8);
		//m_velocity.setX((m_velocity.getX() - m_frictionLeft.getX()));
		turnGordo = SDL_FLIP_HORIZONTAL;

	}
	GameObject::update();
}

void Gordo::clean() {
};
