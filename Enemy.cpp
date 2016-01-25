#pragma once
#include "Enemy.h"
#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

//Constructor y destructor
Enemy::Enemy() {
	m_velocity.setX(0);
	m_velocity.setY(0);
};
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

	if (lado == 1) {
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);
	}
	else {

		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}

};

void Enemy::update()
{

	if (!isCollisionWithTile(m_position)) {
		m_velocity.setX(run);
	}
	else {
	}

	if (!isCollisionWithTile(m_position)) {
		double velo = 0.1 + (m_velocity.getY() - 0.01);
		m_velocity.setY(velo);
	}
	else {
		m_velocity.setY(0);
	}

	//Variable para dar animacion a la textura
	m_currentFrame = (int)(((Game::Instance()->getTicks()) / 100) % m_spriteNum);

	GameObject::update();
	CollisionObject::update();
};

void Enemy::clean() {};