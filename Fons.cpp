#include "Game.h"
#include "Fons.h"
#include "TextureManager.h"


Fons::Fons() {};
Fons::~Fons() {};




void Fons::load(int x, int y, int width, int height,
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

void Fons::load(const LoadPar* lPar)
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
void Fons::draw()
{
	TextureManager::Instance()->drawFrame(m_texid,m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), SDL_FLIP_NONE);
}


void Fons::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, Renderer, SDL_FLIP_HORIZONTAL);
}

void Fons::update() {
	m_x = m_x - 1;
	if (m_x< -1600)m_x = 1600;

	m_currentFrame = (int)((SDL_GetTicks() / 100) % 1);

}
void Fons::clean() {}