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
	cambio = true;
	inicio();
};

void Player::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (&m_position)->getX(), (&m_position)->getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};


void Player::update() {
	// eventos
	ev_right_down = false, ev_left_down = false;
	if (InputHandler::Instance()->isKeyDown(SDLK_RIGHT)) ev_right_down = true;
	if (InputHandler::Instance()->isKeyDown(SDLK_LEFT)) ev_left_down = true;
	if (InputHandler::Instance()->isKeyUp(SDLK_RIGHT)) ev_right_up = true;
	if (InputHandler::Instance()->isKeyUp(SDLK_LEFT)) ev_left_up = true;

	// aceleracion

	if (ev_right_down || ev_left_down) {
		if (calcula_aceleracion() && !calcula_friccion()) inicio();
		if (!calcula_aceleracion()) {
			if (m_velocity.getX() < m_maxVelocity.getX()) aceleracion();
			else {
				m_calc_aceleracion = true;
				m_velocity.setX(m_maxVelocity.getX());
			}
		}
	}

	// velocidad

	if (ev_right_down) horizontal();
	if (ev_left_down) horizontal();
	if (ev_right_up && m_calc_friccion == true) m_calc_friccion = false;
	if (ev_left_up && m_calc_friccion == true)  m_calc_friccion = false;

	// fricion

	if (!calcula_aceleracion() && !calcula_friccion()) inicio();
	if (calcula_aceleracion() && !calcula_friccion()) {
		if (m_velocity.getX() >= 0) {
			friccion();
			horizontal();
		}
		else inicio();
	}

	//framw

	if (cambio == true)  m_currentFrame = (int)((Game::Instance()->getTicks() / 100) % m_sprits);
	cambio = false;


};






void Player::horizontal() {
	if (ev_right_down || ev_right_up) {
		m_flip = 0;
		m_position += m_velocity;
	}
	if (ev_left_down || ev_left_up) {
		m_flip = 1;
		m_position -= m_velocity;
	}
	cambio = true;
}


bool Player::calcula_aceleracion() {
	return m_calc_aceleracion;
}


bool Player::calcula_friccion() {
	return m_calc_friccion;
}


void Player::inicio() {
	m_calc_friccion = true;
	m_calc_aceleracion = false;
	ev_right_up = false;
	ev_left_up = false;
	m_velocity.setX(0);
}


void Player::aceleracion() {
	m_velocity.setX(m_velocity.getX() + m_acceleration.getX());
}
void Player::friccion() {
	m_velocity.setX(m_velocity.getX() - m_friction.getX());
}


void Player::clean() {};

void Player::handleInput()
{
	Vector2D* target = InputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}