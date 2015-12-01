#include "Player.h"
#include "TextureManager.h"
#include "game.h"

Player::Player() {

}
Player::~Player() {

}

void Player::load(const LoaderParams* pParams) {
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_currentRow = 0;
	m_currentFrame = 0;
	m_textureID = pParams->getTextureID();
	m_numSprite = pParams->getNumSprite();
	m_velocity.setX(pParams->getSpeedX());
	m_velocity.setY(pParams->getSpeedY());
	m_acceleration.setX(0);
	m_acceleration.setY(0);
	m_orientation = SDL_FLIP_NONE;
	m_maxVelocity = pParams->getMaxSpeed();
	m_frictionCo = pParams->getFrictionCo();
	m_friction = m_velocity*m_frictionCo;
	m_lastStop.setX(0);
	m_lastStop.setY(0);
}

void Player::draw() {
	//Si la velocidad es negativa, el sprite mira hacia la izquierda
	if (m_velocity.getX() < 0) {
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
		m_orientation = SDL_FLIP_HORIZONTAL;
	}
	//Si la velocidad es positiva, el sprite mira hacia la derecha
	else if (m_velocity.getX() > 0) {
		//refresh img
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentFrame, m_currentRow, Game::Instance()->getRender(), SDL_FLIP_NONE);
		m_orientation = SDL_FLIP_NONE;
	}
	else {
		//refresh img
		TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, 3, m_currentRow, Game::Instance()->getRender(), m_orientation);
	}

	
}

void Player::update() {
	int pixels = 3;
	Vector2D initVelocity = m_velocity;

	if (m_position.getX() < 0) {
		stop(0);
	}
	if (m_position.getX() > ((Game::Instance()->getWindowWidth()) - m_width)) {
		stop((Game::Instance()->getWindowWidth()) - m_width);
	}
	if (m_velocity.getX() < 0) {
		incrementAcceleration();
	}

	if (m_velocity.getX() > 0) {
		decrementAcceleration();
	}

	m_velocity += m_acceleration;

	if (m_velocity.getX()*initVelocity.getX() < 0 || m_velocity.getX() == 0) {
		stop(m_position.getX());
	}

	if (m_velocity.length() > m_maxVelocity) {
		m_velocity = m_velocity.normalize()*m_maxVelocity;
		m_acceleration.setX(0);
	}

	m_position += m_velocity + m_acceleration * 1/2;
	m_currentFrame = (abs((int)(m_position - m_lastStop).length()) / pixels) % m_numSprite;

	InputHandler::Instance()->update();

	if (InputHandler::Instance()->isExitClicked() || InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		Game::Instance()->setIsRunning(false);
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		Game::Instance()->getGameStateMachine()->pushState(new PauseState());
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		incrementAcceleration();
	}

	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		decrementAcceleration();
	}
}

void Player::clean() {
	InputHandler::Instance()->clean();
}

void Player::incrementAcceleration() {
	m_acceleration.setX(m_acceleration.getX() + 0.6);
}

void Player::decrementAcceleration() {
	m_acceleration.setX(m_acceleration.getX() - 0.6);
}

void Player::stop(int xpos) {
	m_lastStop.setX(xpos);
	m_position.setX(xpos);
	m_velocity.setX(0);
	m_acceleration.setX(0);
	m_friction.setX(0);
}