#include "TextureManager.h"
#include "Zep.h"
#include "Game.h"
#include "Camera.h"

Zep::Zep() {
	s_gameObjectID = "Zep";
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_frictionRight.setX(m_velocity.getX() - 0.08);
	m_frictionLeft.setX(m_velocity.getX() - 0.08);
};
Zep::~Zep() {};
SDL_RendererFlip turnZep = SDL_FLIP_HORIZONTAL;

void Zep::draw()
{
	Vector2D cameraPos = Camera::Instance()->getPosition();
	Vector2D posX;
	Vector2D posY;
	//m_position.setX(m_position.getX() - cameraPos.getX());
	//m_position.setY(m_position.getY() - cameraPos.getY());
	//posX.setX(m_position.getX()-cameraPos.getX());
	//posX.setY(m_position.getY());
	posX = m_position - cameraPos;
	
	TextureManager::Instance()->drawFrame(m_textureID,posX.getX(), posX.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), turnZep);
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
	m_pBoundingBox.x = m_position.getX();
	m_pBoundingBox.y = m_position.getY();
	m_pBoundingBox.h = m_height;
	m_pBoundingBox.w = m_width;

	
	GameObject::update();


}

void Zep::clean() {
};
