#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "Camera.h"


Player::Player() { nJump = true; };
Player::~Player() {};

void Player::draw()
{
	if (m_velocity.getX() < 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
		m_lastTimeOrientation = SDL_FLIP_HORIZONTAL;
	}
	else if (m_velocity.getX() > 0) {
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
		m_lastTimeOrientation = SDL_FLIP_NONE;
	}
	else{
		TextureManager::Instance()->drawFrame(m_textureID, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow+1, 0, Game::Instance()->getRender(), m_lastTimeOrientation);
	}
}

void Player::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_textureID = pParams->getTextureID();
	m_spriteNum = pParams->getNum();
	m_currentRow = 0;
	m_lastStop = Vector2D(0,0);
	m_currentFrame = 0;
	m_maxVelocity = pParams->getMaxSpeed();
	m_velocity.setX(pParams->getSpeedX());
	m_velocity.setY(pParams->getSpeedY());
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_frictionCoeficient = pParams->getFrictionCoeficient();
	m_lastTimeOrientation = SDL_FLIP_NONE;
	m_friction = m_velocity*m_frictionCoeficient;
};

void Player::update() {
	
	if (isCollisionWithTile()) {
		if (m_stopAbajo) {
			printf("->HAY COLISION CON SUELO\n");
			stopY(m_stopPositionAbajo.getY()-0.01);
			haycolision = true;
			mjumping = false;
		}
		if (m_stopArriba) {
			printf("->HAY COLISION CON TECHO\n");
			stopY(m_stopPositionArriba.getY()+1);
		}
		/*if (m_stopIzquierda) {
			printf("-->HAY COLISION pared IZQ.\n");
			stopX(m_stopPositionIzquierda.getX()+1);
		}
		if (m_stopDerecha) {
			printf("-->HAY COLISION pared DERECHA.\n");
			stopX(m_stopPositionDerecha.getX()-1);
		}*/

		nJump = false;
	}

	int pixelsToChangeFrame = 12;
	Vector2D v0 = m_velocity;
	SDL_Event event;
	SDL_PollEvent(&event);


	if (m_velocity.getX() > 0) {
		decrementAccelerationX();
	}
	if (m_velocity.getX() < 0) {
		incrementAccelerationX();
	}
	if (m_velocity.getY() > 0) {
		decrementAccelerationY();
	}
	if (m_velocity.getY() < 0) {
		incrementAccelerationY();
	}
	m_velocity += m_acceleration;
	if (m_velocity.getX()*v0.getX() < 0 || m_velocity.getX() == 0) {
		stopX(m_position.getX());
	}
	if (m_velocity.getY()*v0.getY() < 0 || m_velocity.getY() == 0) {
		stopY(m_position.getY());
	}
	if (m_velocity.length() > m_maxVelocity) {
		m_velocity = m_velocity.normalize()*m_maxVelocity;
		m_acceleration.setX(0);
	}
	m_position += m_velocity + m_acceleration * 1 / 2;
	m_currentFrame = (abs((int)(m_position - m_lastStop).length()) / pixelsToChangeFrame) % m_spriteNum;

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		incrementAccelerationX();
	}
	else if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		decrementAccelerationX();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
		decrementAccelerationY();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
		if (!nJump && haycolision) {
			jump();
			nJump = true;
		}

	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
		impulseLeft();
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S)) {
		impulseRight();
	}

	if (m_position.getX() < 0) {
		stopX(0);
	}
	if (m_position.getX() > (Game::Instance()->getScreenWidth() - m_width)) {
		stopX(Game::Instance()->getScreenWidth() - m_width);
	}
	if (m_position.getY() < 0) {
		stopY(0);
	}
	if (m_position.getY() > (Game::Instance()->getScreenHeight() - m_height)) {
		stopY(Game::Instance()->getScreenHeight() - m_height);
	}
	gravity(); //gravedad
	TheCamera::Instance()->setPosition(m_position);
}

void Player::update(int width, int height)
{
}

void Player::stopX(int positionX)
{
	m_lastStop.setX(positionX);
	m_position.setX(positionX);
	m_velocity.setX(0);
	m_acceleration.setX(0);
	m_friction.setX(0);
}

void Player::stopY(int positionY)
{
	m_lastStop.setY(positionY);
	m_position.setY(positionY);
	m_velocity.setY(0);
	m_acceleration.setY(0);
	m_friction.setY(0);
}

void Player::incrementAccelerationX()
{
	m_acceleration.getX() < 0.2 ? m_acceleration.setX(m_acceleration.getX() + 0.1) : "";
}

void Player::gravity()
{
	m_acceleration.setY(m_acceleration.getY() + 0.2);
}

void Player::decrementAccelerationX()
{
	m_acceleration.setX(m_acceleration.getX() - 0.1);
}
void Player::incrementAccelerationY()
{
	m_acceleration.getY() < 0.2 ? m_acceleration.setY(m_acceleration.getY() + 0.1) : "";
}
void Player::decrementAccelerationY()
{
	m_acceleration.setY(m_acceleration.getY() - 0.1);
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
	mjumping = true;
	haycolision = false;
	m_velocity.setY(-12);
}

void Player::onCollsion(GameObject * other)
{
}

/*void Player::collision() {
	return ;
}*/
;

