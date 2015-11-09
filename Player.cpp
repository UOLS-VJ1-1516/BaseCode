#include "Game.h"
#include "Player.h"
#include "TextureManager.h"

Player::Player() {};
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
	resetParams();	
};

void Player::draw() {	
	TextureManager::Instance()->drawFrame(m_textureID, (&m_position)->getX(), (&m_position)->getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};


void Player::update() {	
	registerEvents();
	calculateAcceleration();
	calculateVelocity();
	calculateFriction();
	calculateFrame();
};


void Player::registerEvents() {
	eventRightDown = false, eventLeftDown = false;
	if (InputHandler::Instance()->isKeyDown(SDLK_RIGHT)) eventRightDown = true;
	if (InputHandler::Instance()->isKeyDown(SDLK_LEFT)) eventLeftDown = true;
	if (InputHandler::Instance()->isKeyUp(SDLK_RIGHT)) eventRightUp = true;
	if (InputHandler::Instance()->isKeyUp(SDLK_LEFT)) eventLeftUp = true;
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
		m_position += m_velocity;
	} 
	if (eventLeftDown || eventLeftUp) {
		m_flip = 1;
		m_position -= m_velocity;
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
	m_velocity.setX(0);
}


void Player::incrementAccelerationX() {
	m_velocity.setX(m_velocity.getX() + m_acceleration.getX());
}
void Player::incrementFriction() {
	m_velocity.setX(m_velocity.getX() - m_friction.getX());
}


void Player::clean() {};
