#include "GameObject.h"




GameObject::GameObject() {




}


GameObject::~GameObject() {




}

void GameObject::load(const Params* pParams) {

	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_spriteNum = pParams->getSpriteNum();
	m_currentRow = pParams->getRowNum();
	m_flip = pParams->getFlip();

	TextureManager::Instance()->load(m_fileName, m_textureID, Game::Instance()->getRenderer());
}

void GameObject::draw() {



}

void GameObject::update() {





}


void GameObject::clean() {




}