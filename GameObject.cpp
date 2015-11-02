#pragma once
#include "GameObject.h"

GameObject::GameObject()
{
}
GameObject::~GameObject()
{
}

void GameObject::load(const LoaderParams* pParams){

	m_x = pParams->getX();
	m_y = pParams->getY();

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();

	m_textureID = pParams->getTextureID();
	m_numsprites = pParams->getNumSprites();
	m_currentFrame = 0;
	m_currentRow = 0;

}


void GameObject::draw()
{
	
}

void GameObject::update()
{
	
}
void GameObject::clean()
{
	SDL_Quit();
}
