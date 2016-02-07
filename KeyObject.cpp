#pragma once
#include "Game.h"
#include "KeyObject.h"
#include "TextureManager.h"
#include "Camera.h"

KeyObject::KeyObject() {
	m_position = Vector2D(0, 0);
};
KeyObject::~KeyObject() {};

void KeyObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, m_position.getX()-TheCamera::Instance()->getPosition().getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
}

void KeyObject::drawRotation(int angle)
{
	TextureManager::Instance()->draw(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, angle, Game::Instance()->getRender(), SDL_FLIP_NONE);
}
void KeyObject::onCollision(GameObject * go)
{
}
;

void KeyObject::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_maxVelocity = pParams->getMaxSpeed();
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_friction.setX(1000);
	m_friction.setY(1000);
}

void KeyObject::clean()
{
}
void KeyObject::stopX(int)
{
}
void KeyObject::stopY(int)
{
}
;

void KeyObject::update() {
	m_pBoundingBox.x = m_position.getX() + m_collisionMargin;
	m_pBoundingBox.y = m_position.getY();
	m_pBoundingBox.h = m_height;
	m_pBoundingBox.w = m_width - 2 * m_collisionMargin;
	int framesPorSegundo = 10;
	m_currentFrame = (int)((((Game::Instance()->getTicks())*framesPorSegundo) / 1000) % m_spriteNum); //canvia 10 veces por segundo
};

