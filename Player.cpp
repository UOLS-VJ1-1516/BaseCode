#include "Game.h"
#include "Player.h"
#include "texturemanager.h"

Player::Player() {}
Player::~Player() {}




bool Player::load(const LoadPar* lPar) {

	m_width = lPar->getwidth();
	m_height = lPar->getheight();
	m_x = lPar->getx();
	m_y = lPar->gety();
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_currentFrame = lPar->getcurrentFrame();
	m_flip = lPar->getflip();
	return true;
}


bool Player::load(int x, int y, int width, int height, char* id) {

	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_texid = id;
	m_currentFrame = 0;
	m_currentRow = 0;
	m_flip = 0;
	return true;
}

void Player::draw(SDL_Renderer* lRender) {
	TextureManager::Instance()->drawFrame(m_texid, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, lRender, SDL_FLIP_NONE);
	SDL_RenderPresent(lRender);
	
}
void Player::draw() {

	TextureManager::Instance()->drawFrame(m_texid, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), SDL_FLIP_NONE);

	//id, x, y, width, height, currentRow, currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_NONE);

}
void Player::update() {
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_currentFrame);
	
}


void Player::clean() {}