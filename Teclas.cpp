#include "Game.h"
#include "Teclas.h"
#include "OverState.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Camera.h"



Teclas::Teclas() {};
Teclas::~Teclas() {};



void Teclas::load(const LoadPar* lPar)
{
	Teclas::Params = lPar;
	m_width = lPar->getWidth();
	m_height = lPar->getHeight();
	m_position.setX(lPar->getX());
	m_position.setY(lPar->getY());
	m_texid = lPar->getTextureID();
	m_sprits = lPar->getNumSprites();
	m_velocity.setX(0);  //Velocidad horizontal inicial
	m_velocity.setY(0);  //Velocidad verical inicial
	m_currentFrame = 1;
	m_currentRow = 1;
	m_flip = 1;
	m_anchopantalla = Game::Instance()->getAncho();
	m_altopantalla = Game::Instance()->getAlto();



};
void Teclas::draw()
{
	Vector2D cameraPos = Camera::Instance()->getPosition();
	Vector2D posX;
	Vector2D posY;
	posX = m_position - cameraPos;


	TextureManager::Instance()->drawFrame(m_texid, posX.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);
}


void Teclas::draw(SDL_Renderer* Renderer) {
	Vector2D cameraPos = Camera::Instance()->getPosition();
	Vector2D posX;
	Vector2D posY;
	posX = m_position - cameraPos;
	TextureManager::Instance()->drawFrame(m_texid, posX.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}

void Teclas::update() {

	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);

}

void Teclas::clean() {}