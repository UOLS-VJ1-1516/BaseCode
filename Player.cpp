#include "Game.h"
#include "Player.h"
#include "TextureManager.h"


Player::Player() {};
Player::~Player() {};


void Player::load(int x, int y, int width, int height,
	std::string texid)
{
	m_x = x;
	m_y = y;
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
	m_x = lPar->getx();
	m_y = lPar->gety();
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_sprits = lPar->getsprits();
	m_flip = lPar->getflip();

};
void Player::draw()
{

	TextureManager::Instance()->drawFrame(m_texid,m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}


void Player::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Renderer, m_flip);
	
}

void Player::update() {

	m_x = m_x + 2;
	if (m_x >1600)m_x= -100;
	
	//if ((m_currentRow == 2) &&(m_currentFrame == 6)) { m_currentRow = 3; m_currentFrame = 1; m_sprits = 1; }
	
	//if ((m_currentRow == 1) && (m_currentFrame == 2)) { m_currentRow = 3; m_currentFrame = 1; m_sprits = 1; }
		m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
		
	
	
	//if ((m_currentRow == 3) && (m_currentFrame == 1)) { m_currentRow = 1; m_currentFrame = 1; m_sprits = 4; }
	
}
void Player::clean() {}