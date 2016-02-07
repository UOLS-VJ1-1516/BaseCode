#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "Camera.h"
#include <cmath>
#include "SoundManager.h"
#include "GameOver.h"


Player::Player() {
	m_position = Vector2D(0, 0);
};
Player::~Player() {};

void Player::draw()
{
	if (m_velocity.getX() < -m_epsilon) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
		m_lastTimeOrientation = SDL_FLIP_HORIZONTAL;
	}
	else if (m_velocity.getX() > m_epsilon) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
		m_lastTimeOrientation = SDL_FLIP_NONE;
	}
	else{
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX() - TheCamera::Instance()->getPosition().getX(), m_position.getY(), m_width, m_height, m_currentRow+1, 0, Game::Instance()->getRender(), m_lastTimeOrientation);
	}
}

void Player::load(const LoaderParams* pParams)
{
	m_saltoBase = false;
	m_epsilon = 0.5;
	m_saltoAire = false;
	m_estoyEnElSuelo = false;
	m_currentRow = 0;
	m_lastStop = Vector2D(0,0);
	m_currentFrame = 0;
	m_lastTimeOrientation = SDL_FLIP_NONE;
	m_friction = m_velocity*(-m_frictionCoeficient);
	m_ticksHastaProximoSalto = 7;
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_maxVelocity = pParams->getMaxSpeed();
	m_velocity.setX(pParams->getSpeedX());
	m_velocity.setY(pParams->getSpeedY());
	m_frictionCoeficient = pParams->getFrictionCoeficient();

};

void Player::update() {
	m_pBoundingBox.x = m_position.getX() + m_collisionMargin;
	m_pBoundingBox.y = m_position.getY();
	m_pBoundingBox.h = m_height;
	m_pBoundingBox.w = m_width - 2 * m_collisionMargin;
	
	int pixelsToChangeFrame = 12;
	m_ticksHastaProximoSalto--;

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(5);
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-5);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		if (m_ticksHastaProximoSalto <= 0) {
			m_ticksHastaProximoSalto = 7;
			if (m_saltoAire) {
				if (m_saltoBase) {
					m_saltoBase = false;
					jump();
				}
				else {
					m_saltoAire = false;
					jump();
				}
			}
		}

	}

	m_position += m_velocity;
	m_currentFrame = (abs((int)(m_position - m_lastStop).length()) / pixelsToChangeFrame) % m_spriteNum;
	CollisionObject::update();
	if (m_position.getY() >= (Game::Instance()->getScreenHeight()-m_height) || colisionmuerte) {
		Game::Instance()->getGameStateMachine()->pushState(new GameOver());
	}
}

void Player::update(int width, int height)
{
}

void Player::incrementAccelerationX()
{
	//m_acceleration.setX(m_acceleration.getX() + 0.3);
}
void Player::decrementAccelerationX()
{
	//m_acceleration.setX(m_acceleration.getX() - 0.3);
}
void Player::incrementAccelerationY()
{
	//m_acceleration.setY(m_acceleration.getY() + 0.3);
}
void Player::decrementAccelerationY()
{
	//m_acceleration.setY(m_acceleration.getY() - 0.3);
}

void Player::impulseRight()
{
	m_acceleration.setX(0);
	m_velocity.setX(m_maxVelocity);
}
void Player::impulseLeft()
{
	m_acceleration.setX(0);
	m_velocity.setX(-m_maxVelocity);
}

void Player::jump()
{
	//m_acceleration.setY(m_acceleration.getY() - 0.6);
	SoundManager::Instance()->playSound("jump", 0, 1);
	m_velocity.setY(-m_maxVelocity);
}

void Player::stopX(int positionX)
{
	m_lastStop.setX(positionX);
	m_position.setX(positionX);
	m_velocity.setX(0);
	m_acceleration.setX(0);

}

void Player::stopY(int positionY)
{
	m_lastStop.setY(positionY);
	m_position.setY(positionY);
	m_velocity.setY(0);
	//m_acceleration.setY(0);
	m_friction.setY(0);
	/*m_position.setY(positionY);
	m_velocity.setY(m_velocity.getY()*-1);
	//m_acceleration.setY(0);
	m_friction.setY(0);*/
}