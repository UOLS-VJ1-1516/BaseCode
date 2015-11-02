//Class Enemy para crear un GameObject Enemy
#include "enemy.h"
#include "TextureManager.h"
#include "game.h"

//Constructor y destructor
enemy::enemy() {};
enemy::~enemy() {};

/*Funcion load que recibe todos lo parametros para hacer el load del Enemy,
envia los parametros necesarios a la clase TextureManager para cargar la textura
y envia los parametros para crear el mapa de texturas*/
void enemy::load(const LoaderParams* pParams) {
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_x = pParams->getX();
	m_y = pParams->getY();
	m_textureID = pParams->getTextureID();
	m_fileName = pParams->getFileName();
	m_spriteNum = pParams->getSpriteNum();
	m_currentRow = pParams->getRowNum();
	TextureManager::Instance()->load(m_fileName, m_textureID, game::Instance()->getRenderer());
	TextureManager::Instance()->setFrame(m_textureID, m_x, m_y, m_width, m_height);
};

//Funcion para mostrar por pantalla la textura mediante la clase TextureManager
void enemy::draw() {

	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, game::Instance()->getRenderer(), SDL_FLIP_NONE);
};

void enemy::update()
{
	//Variable para dar animacion a la textura
	m_currentFrame = (int)(((game::Instance()->getTicks()) / 100) % m_spriteNum);
};

void enemy::clean() {};
