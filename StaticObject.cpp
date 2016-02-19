#include "Game.h"
#include "StaticObject.h"
#include "TextureManager.h"

StaticObject::StaticObject() {};
StaticObject::~StaticObject() {};

void StaticObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	/*if (m_velocity.getX() < 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);

	}
	else if (m_velocity.getX() > 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);

	}*/

}

void StaticObject::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	//m_lastStop = Vector2D(0, 0);
	m_currentFrame = 0;
	//m_speedMax = pParams->getSpeedMax();
	m_velocity.setX(pParams->getSpeed_x());
	m_velocity.setY(pParams->getSpeed_y());
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	//m_friction = pParams->getFriction();
	//m_lastTimeOrientation = SDL_FLIP_NONE;
	//m_friction = m_velocity*m_friction;
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());

};

void StaticObject::update() {
	/*if ((m_position.getX() < 0 && m_velocity.getX() < 0) || (m_position.getX() > (Game::Instance()->getScreenWidth() - m_width) && m_velocity.getX() > 0)) {
		m_velocity *= -1;
	}

	m_position += m_velocity;*/
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);

};

void StaticObject::clean() {
};

void StaticObject::onCollision(GameObject * other)
{
};