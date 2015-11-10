#include "StaticObject.h"
#include "TextureManager.h"
#include "game.h"

StaticObject::StaticObject() {

}
StaticObject::~StaticObject() {

}

void StaticObject::load(const LoaderParams* pParams) {
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_textureID = pParams->getTextureID();
	m_numSprite = pParams->getNumSprite();
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_maxVelocity = pParams->getMaxSpeed();
	m_friction.setX(0);
	m_friction.setY(0);
}

void StaticObject::draw() {
	//refresh img
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void StaticObject::update() {
	m_currentFrame = ((Game::Instance()->getTicks() / 100) % m_numSprite);
}

void StaticObject::clean() {

}
