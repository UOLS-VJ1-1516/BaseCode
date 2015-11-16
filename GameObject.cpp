#pragma once
#include "GameObject.h"
#include "game.h"
#include "TextureManager.h"

GameObject::GameObject()
{
}
GameObject::~GameObject()
{
}

void GameObject::load(const LoaderParams* pParams){

	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
	m_numsprites = pParams->getNumSprites();
	m_currentFrame = 0;
	m_currentRow = 0;

}


void GameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID,
		(int)m_position.getX(), (int)m_position.getY(),
		m_width, m_height,
		m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
}

void GameObject::update()
{
	m_position += m_velocity;
}
void GameObject::clean()
{
	SDL_Quit();
}
