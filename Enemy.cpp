#include "Game.h"
#include "Enemy.h"
#include "TextureManager.h"


Enemy::Enemy() {};
Enemy::~Enemy() {};



void Enemy::load(const LoadPar* lPar)
 {
	 Enemy::Params = lPar;
	 m_width = lPar->getWidth();
	 m_height = lPar->getHeight();
	 m_position.setX(lPar->getX());
	 m_position.setY(lPar->getY());
	 m_texid = lPar->getTextureID();
	 m_sprits = lPar->getNumSprites();
	 m_currentFrame = 1;
	 m_currentRow = 1;
	 m_flip = 2;
	 m_anchopantalla = Game::Instance()->getAncho();
	 m_altopantalla = Game::Instance()->getAlto();
	

	
	}; 
void Enemy::draw()
{
	
	TextureManager::Instance()->drawFrame(m_texid,m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);
	
}


void Enemy::draw(SDL_Renderer* Renderer) {
	printf("EI\n\n");
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}

void Enemy::update() {
	
	m_position.setX(m_position.getX()-3);
	if (m_position.getX() < -200.00)m_position.setX(m_anchopantalla);
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
}
void Enemy::clean() {}