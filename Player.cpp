#include "Game.h"
#include "Player.h"
#include "TextureManager.h"


Player::Player() {};
Player::~Player() {};


void Player::load(float x, float y, int width, int height,
	std::string texid)
{
	m_position.setX(x);
	m_position.setY(y);
	m_width = width;
	m_height = height;
	m_texid = texid;
	m_currentFrame = 1;
	m_currentRow = 1;
	m_sprits = 1;
	
}

void Player::load(const LoadPar* lPar)
{
	m_width = lPar->getwidth();
	m_height = lPar->getheight();
	m_position.setX(lPar->getx());
	m_position.setY(lPar->gety());
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_sprits = lPar->getsprits();
	m_flip = lPar->getflip();

	m_velocity.setX(10);  //Velocidad horizontal inicial
	m_velocity.setY(0);

};
void Player::draw()
{

	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}


void Player::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Renderer, m_flip);
	
}

void Player::update() {

	if (m_position.getX() > 1400) {   //Adaptarlo al ancho de pantalla
		m_velocity.setX(-10);
		m_flip = 2;
	}
	else if (m_position.getX() < 0) {
		m_velocity.setX(10);
		m_flip = 1;
	}

	m_position+=m_velocity; //Suma de vectores sobrecargando operador +=
	
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
		
	
}
void Player::clean() {}