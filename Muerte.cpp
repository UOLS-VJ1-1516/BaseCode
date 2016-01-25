#pragma once
#include "Muerte.h"
#include "TextureManager.h"
#include "Game.h"
#include "Vector2D.h"

//Constructor y destructor
Muerte::Muerte() {};
Muerte::~Muerte() {};

/*Funcion load que recibe todos lo parametros para hacer el load del Enemy,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void Muerte::load(const LoaderParams* pParams) {
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
void Muerte::draw() {

};

void Muerte::update()
{

};

void Muerte::clean() {};