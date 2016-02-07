#include "Game.h"
#include "Player2.h"
#include "TextureManager.h"


Player2::Player2() {};
Player2::~Player2() {};

void Player2::load(const LoaderParams* pParams)
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
	stateFlip = true;
	m_callbackID = pParams->getCallbackID();
};

void Player2::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (&m_position)->getX(), (&m_position)->getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};

void Player2::update() {

	if (!stateFlip) {
		m_position -= (m_velocity);
		m_flip = 1;
		if (0 >= m_position.getX()) stateFlip = true;
	}
	if (stateFlip) {
		if (Game::Instance()->get_ancho_ventana() <= m_position.getX() + m_width) stateFlip = false;
		m_position += (m_velocity);
		m_flip = 0;

	}

	m_currentFrame = (int)((Game::Instance()->getTicks() / 100) % m_sprits);
};

void Player2::onCollsion(GameObject * other)
{
}
;

void Player2::clean() {

}
