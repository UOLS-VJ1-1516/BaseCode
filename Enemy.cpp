#include "Game.h"
#include "Enemy.h"
#include "CollisionObject.h"
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
	 m_currentRow = 2;
	 m_flip = 2;
	 m_anchopantalla = Game::Instance()->getAncho();
	 m_altopantalla = Game::Instance()->getAlto();
	

	
	}; 
void Enemy::draw()
{
	
	TextureManager::Instance()->drawFrame(m_texid,m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);
	
}


void Enemy::draw(SDL_Renderer* Renderer) {
	
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}

void Enemy::update() {
	
	
	//if (m_position.getX() < -200.00)m_position.setX(m_anchopantalla);
	
	if (isCollisionEnemyWithDown(this)) {
		
		m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);
		m_position.setX(m_position.getX() - 3);
		//caigo = false;
		m_velocitySalto.setY(0);
		//puedojump = true;
	}
	if (!isCollisionEnemyWithDown(this)) {
		
		//puedojump = false;
		//caigo = true;
		if (m_position.getY() < Game::Instance()->getAlto()) {
			//m_sprits = 1;
			//m_currentRow = 4;
			m_position.setY(m_position.getY() + 5);

		}


	}
}
void Enemy::clean() {}