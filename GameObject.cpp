#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"

GameObject::GameObject() {

};

GameObject::~GameObject() {

};

void GameObject::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	TextureManager::Instance()->load("sonic.bmp", m_textureID, Game::Instance()->getRenderer());
	TextureManager::Instance()->setFrame("player", x, y, width, height);
};

void GameObject::draw() {
	TextureManager::Instance()->drawFrame("Player", 300, 200, 104, 151, 0, spriteNum, Game::Instance()->getRender(), SDL_FLIP_NONE);
};

void GameObject::update() {};
void GameObject::clean() {};