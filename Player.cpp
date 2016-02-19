#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "Camera.h"

Player::Player() { nJump = true; };
Player::~Player() {};

void Player::load(const LoaderParams* pParams)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();	
	m_currentRow = pParams->getCurrentRow();
	m_sprits = pParams->getSprits();
	m_flip = pParams->getFlip();
	m_position = pParams->getPosition();
	m_velocity = pParams->getVelocity();
	m_maxVelocity = pParams->getMaxVelocity();
	m_acceleration = pParams->getAcceleration();
	m_friction = pParams->getFriction();
	m_changes = true;
	m_callbackID = pParams->getCallbackID();
	m_lastStop = Vector2D(0, 0);
	aceleracionY = true;
	frictionY = false;
	mjumping = false;
	resetParams();	
	mgravity = true;
};


void Player::draw() {	
	TextureManager::Instance()->drawFrame(m_textureID, (&m_position)->getX(), (&m_position)->getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};


void Player::update() {
	if (isCollisionWithTile()) {
		if (m_stopAbajo) {
			stopY(m_stopPositionAbajo.getY() - 0.01);
			haycolision = true;
		} 	

		

		nJump = false; 
	} else haycolision = false;
	

	if (mjumping == false && mgravity == true && haycolision == false) {
		m_position.setY(m_position.getY() + 4);
	}
	registerEvents();


	if (nJump && m_stopAbajo) {
		nJump = false;
		mgravity = false;
		m_velocity.setY(0);
		jump();
	}
	
	if (mjumping) {
		if (m_velocity.getY() <= m_maxVelocity.getY() && aceleracionY == true && frictionY==false) {
			m_velocity.setY(m_velocity.getY() + m_acceleration.getY());
		}

		if (m_velocity.getY() >= m_maxVelocity.getY() && aceleracionY == true && frictionY == false) aceleracionY = false, frictionY = true;
		if (m_velocity.getY() >= 0 && aceleracionY == false && frictionY == true) {
			m_velocity.setY(m_velocity.getY() - m_friction.getY());
		}
		if (m_velocity.getY() <= 0 && aceleracionY == false && frictionY == true) {
			frictionY = false;
		}

		if (mjumping && aceleracionY == true) {
			m_position.setY(m_position.getY() - m_velocity.getY());
		}

		if (aceleracionY == false && frictionY == true) {
			frictionY = false;
			aceleracionY = true;
			mjumping = false;
			mgravity = true;
		}
		
	}

	calculateAcceleration();
	calculateVelocity();
	calculateFriction();
	if (m_stopArriba) {
		m_position.setY(m_position.getY() + 4);
		m_position.setX(m_position.getX() - 4);
	}

	calculateFrame();

	if (m_position.getX() < 0) {
		stopX(0);
	}
	if (m_position.getX() > (Game::Instance()->getwidthWindow() - m_width)) {
		stopX(Game::Instance()->getwidthWindow() - m_width);
	}
	if (m_position.getY() < 0) {
		stopY(0);
	}
	if (m_position.getY() > (Game::Instance()->getHeightWindow() - m_height)) {
		stopY(Game::Instance()->getHeightWindow() - m_height);
	}

	if (isCollisionWithTile()) {
		if (m_stopDerecha || m_stopIzquierda) {			
			stopX(m_lastStop.getX());
			if (m_lastStop.getX() != m_position.getX()) {
				m_lastStop = m_position;
			}
		}
	}
	else {
		m_lastStop = m_position;
	}

}


void Player::registerEvents() {
	eventRightDown = false, eventLeftDown = false;
	if (InputHandler::Instance()->isKeyDown(SDLK_RIGHT)) eventRightDown = true;
	if (InputHandler::Instance()->isKeyDown(SDLK_LEFT)) eventLeftDown = true;
	if (InputHandler::Instance()->isKeyUp(SDLK_RIGHT)) eventRightUp = true;
	if (InputHandler::Instance()->isKeyUp(SDLK_LEFT)) eventLeftUp = true;
	if (InputHandler::Instance()->isKeyDown(32) && mjumping == false) nJump = true;
}


void Player::calculateAcceleration() {
	if (eventRightDown || eventLeftDown) {
		if (isCalculateAcceleration() && !iscalculateFriction()) resetParams();
		if (!isCalculateAcceleration()) {
			if (m_velocity.getX() < m_maxVelocity.getX()) incrementAccelerationX();
			else {
				m_accelerationCalculate = true;
				m_velocity.setX(m_maxVelocity.getX());
			}
		}
	}
}




void Player::calculateFriction() {
	if (!isCalculateAcceleration() && !iscalculateFriction()) resetParams();
	if (isCalculateAcceleration() && !iscalculateFriction()) {
		if (m_velocity.getX() >= 0) {
			incrementFriction();
			frontHorizontal();
		}
		else resetParams();
	}
}


void Player::calculateVelocity() {
	if (eventRightDown) frontHorizontal();	
	if (eventLeftDown) frontHorizontal();
	if (mjumping) frontHorizontal();
	if (eventRightUp && m_frictionCalculate == true) m_frictionCalculate = false;
	if (eventLeftUp && m_frictionCalculate == true)  m_frictionCalculate = false;
}


void Player::calculateFrame() {
	if (m_changes == true)  m_currentFrame = (int)((Game::Instance()->getTicks() / 100) % m_sprits);
	m_changes = false;
}


void Player::frontHorizontal() {	
	if (eventRightDown || eventRightUp ) {
		m_flip = 0;
		m_position.setX(m_position.getX() + m_velocity.getX());
	} 
	if (eventLeftDown || eventLeftUp) {
		m_flip = 1;
		m_position.setX(m_position.getX() - m_velocity.getX());
	}
	m_changes = true;
}


bool Player::isCalculateAcceleration() {
	return m_accelerationCalculate;
}


bool Player::iscalculateFriction() {
	return m_frictionCalculate;
}


void Player::resetParams() {
	m_frictionCalculate = true;
	m_accelerationCalculate = false;
	eventRightUp = false;
	eventLeftUp = false;
}


void Player::incrementAccelerationX() {
	float tmp = 0;
	if (aceleracionY == true && frictionY == false) tmp = m_velocity.getX() + m_acceleration.getX() * 2;
	else tmp = m_velocity.getX() + m_acceleration.getX();
	m_velocity.setX(tmp);
}
void Player::incrementFriction() {
	m_velocity.setX(m_velocity.getX() - m_friction.getX());
}


void Player::impulseRight()
{
	m_acceleration.setX(0);
	m_velocity.setX(m_maxVelocity.getX());
}
void Player::impulseLeft()
{
	m_acceleration.setX(0);
	m_velocity.setX(-m_maxVelocity.getX());
}

void Player::jump()
{
	//m_acceleration.setY(m_acceleration.getY() - 0.6);
	mjumping = true;
	haycolision = false;
}

void Player::onCollsion(GameObject * other)
{
}

void Player :: clean() {

}

void Player::stopX(int positionX)
{
	m_lastStop.setX(positionX);
	m_position.setX(positionX);

}

void Player::stopY(int positionY)
{
	m_lastStop.setY(positionY);
	m_position.setY(positionY);
}

void Player::gravity()
{
	m_acceleration.setY(m_acceleration.getY() + 0.2);
}

void Player::incrementAccelerationY()
{
	m_acceleration.getY() < 0.2 ? m_acceleration.setY(m_acceleration.getY() + 0.1) : "";
}
void Player::decrementAccelerationY()
{
	m_acceleration.setY(m_acceleration.getY() - 0.1);
}