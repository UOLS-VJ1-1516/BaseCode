#pragma once
#include "Enemy.h"
#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

//Constructor y destructor
Enemy::Enemy() {};
Enemy::~Enemy() {};

/*Funcion load que recibe todos lo parametros para hacer el load del Enemy,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void Enemy::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_spriteNum = pParams->getSpriteNum();
	m_currentRow = pParams->getRowNum();
	TextureManager::Instance()->load(m_fileName, m_textureID, Game::Instance()->getRenderer());
};

//Funcion para mostrar por pantalla la textura mediante la clase TextureManager
void Enemy::draw() {

	if (dreta) {
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
	}
	else {
		
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}

};

void Enemy::update()
{
	
	if ((int)m_position.getX() >= (900- m_width + 10)) {
		dreta = false;
		
	}
	else if((int)m_position.getX() <= 0){
		dreta = true;
	}

	if (dreta) {
		m_position.setX(m_position.getX() + 3);
	}
	else {
		
		//printf("%d, ", pos);
		m_position.setX(m_position.getX() - 3);
		
	}
	
	//Variable para dar animacion a la textura
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);


};

void Enemy::clean() {};