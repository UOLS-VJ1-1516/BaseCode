#include "GameObject.h"
#include "TextureManager.h"
#include "game.h"

//Constructor y destructor
GameObject::GameObject()
{
}
GameObject::~GameObject()
{
}

//Función para cargar los parametros de los diferentes game objects
void GameObject::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_spriteNum = pParams->getSpriteNum();
	m_currentRow = pParams->getRowNum();
	TextureManager::Instance()->load(m_fileName, m_textureID, Game::Instance()->getRenderer());
}

void GameObject::draw()
{
}

void GameObject::update()
{
}
void GameObject::clean()
{
}