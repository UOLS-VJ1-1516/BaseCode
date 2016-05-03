#include "Game.h"
#include "Enemy.h"
#include "OverState.h"
#include "CollisionObject.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Camera.h"



Enemy::Enemy() {};
Enemy::~Enemy() {};

int coli = 1;

void Enemy::load(const LoadPar* lPar)
 {
	 Enemy::Params = lPar;
	 m_width = lPar->getWidth();
	 m_height = lPar->getHeight();
	 m_position.setX(lPar->getX());
	 m_position.setY(lPar->getY());
	 m_texid = lPar->getTextureID();
	 m_sprits = lPar->getNumSprites();
	 m_velocity.setX(0);  //Velocidad horizontal inicial
	 m_velocity.setY(0);  //Velocidad verical inicial
	 m_currentFrame = 1;
	 m_currentRow = 2;
	 m_flip = 2;
	 m_anchopantalla = Game::Instance()->getAncho();
	 m_altopantalla = Game::Instance()->getAlto();
	

	
	}; 
void Enemy::draw()
{
	Vector2D cameraPos = Camera::Instance()->getPosition();
	Vector2D posX;
	Vector2D posY;
	posX = m_position - cameraPos;
	

	TextureManager::Instance()->drawFrame(m_texid, posX.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);
}


void Enemy::draw(SDL_Renderer* Renderer) {
	Vector2D cameraPos = Camera::Instance()->getPosition();
	Vector2D posX;
	Vector2D posY;
	posX = m_position - cameraPos;
	TextureManager::Instance()->drawFrame(m_texid, posX.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);

}

void Enemy::update() {
	
		
		if (isCollisionEnemyWithDown(this)) {
			m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);

			if (isCollisionEnemyWithLeft(this)) {

				m_velocity.setX(3);
				m_flip = 1;

				m_position.setX(m_position.getX() + m_velocity.getX());

			}
			else {

				if (m_flip == 2) {
					m_velocity.setX(-3);
					m_position.setX(m_position.getX() + m_velocity.getX());
				}
				if (m_flip == 1) {
					m_velocity.setX(3);
					m_position.setX(m_position.getX() + m_velocity.getX());

				}

			}
			if (isCollisionEnemyWithRight(this)) {

				m_velocity.setX(-3);
				m_flip = 2;
				m_position.setX(m_position.getX() + m_velocity.getX());
			}
			else {

				if (m_flip == 2) {
					m_velocity.setX(-3);
					m_position.setX(m_position.getX() + m_velocity.getX());
				}
				if (m_flip == 1) {
					m_velocity.setX(3);
					m_position.setX(m_position.getX() + m_velocity.getX());

				}

			}

		}
		if (!isCollisionEnemyWithDown(this)) {

			//puedojump = false;
			//caigo = true;
			if (m_position.getY() < Game::Instance()->getAlto()) {
				//m_sprits = 1;
				//m_currentRow = 4;
				m_position.setY(m_position.getY() + 5);

			}


			if (m_position.getY() > m_altopantalla - 50) {

				m_currentRow = 3;
				m_currentFrame = 0;
			}
			if (m_position.getY() > m_altopantalla - 25) {

				m_currentRow = 3;
				m_currentFrame = 2;
			}
			if (m_position.getY() > m_altopantalla - 10) {

				m_currentRow = 3;
				m_currentFrame = 3;
			}
			if (m_position.getY() > m_altopantalla) {

				m_currentRow = 3;
				m_currentFrame = 4;
			}


		}
	}

void Enemy::clean() {}