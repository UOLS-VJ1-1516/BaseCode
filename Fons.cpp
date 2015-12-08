#include "Game.h"
#include "Fons.h"
#include "TextureManager.h"


Fons::Fons() {};
Fons::~Fons() {};




void Fons::load(float x, float y, int width, int height,
	std::string texid)
{
	m_position.setX(float(x));
	m_position.setX(float(y));
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
	m_position.setX(lPar->getx());
	m_position.setY(lPar->gety());
	m_texid = lPar->gettexid();
	m_currentRow = lPar->getcurrentRow();
	m_sprits = lPar->getsprits();
	m_anchopantalla = lPar->getanchopantalla();
	m_altopantalla = lPar->getaltopantalla();
	m_flip = lPar->getflip();

};
void Fons::draw()
{
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);
}


void Fons::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Renderer, m_flip);
}

void Fons::update() {
   // m_position.setX(m_position.getX() -2);
	//if (m_position.getX()< -1600)m_position.setX(1600);

	m_currentFrame = (int)((SDL_GetTicks() / 100) % 1);

}
void Fons::clean() {}