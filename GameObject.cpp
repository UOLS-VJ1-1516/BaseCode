#pragma once
#include "GameObject.h"
#include "game.h"

void GameObject::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_currentRow = 0;
	m_spriteNum = pParams->getSpriteNum();
	TextureManager::Instance()->load(m_fileName, m_textureID, Game::Instance()->getRender());
}

void GameObject::clean() {}
void GameObject::draw() {}
void GameObject::update() {};
