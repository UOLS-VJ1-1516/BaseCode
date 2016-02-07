#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "Camera.h"


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
	m_callbackID = pParams->getCallbackID();
	inicio();
	m_lastStop = Vector2D(0, 0);
	aceleracionY = true;
	frictionY = false;
	mjumping = false;
	mgravity = true;
};

void Player::draw() {
	TextureManager::Instance()->drawFrame(m_textureID, (&m_position)->getX(), (&m_position)->getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->getRenderer(), m_flip);
};


void Player::update() {

	if (isCollisionWithTile()) {
		if (m_stopAbajo) {
			//printf("->HAY COLISION CON SUELO\n");
			stopY(m_stopPositionAbajo.getY() - 0.01);
			haycolision = true;
		}
		if (m_stopArriba) {
			//printf("->HAY COLISION CON TECHO\n");
			stopY(m_stopPositionArriba.getY() + 1);
		}

		/*	if (m_stopDerecha) {
		printf("->HAY COLISION CON derecha\n");
		stopX(m_stopPositionDerecha.getX());
		}
		if (m_stopIzquierda) {
		printf("->HAY COLISION CON izquierda\n");
		stopX(m_stopPositionIzquierda.getX());
		}*/
		nJump = false;
	}
	else haycolision = false;

	if (mjumping == false && mgravity == true && haycolision == false) {
		m_position.setY(m_position.getY() + 7);
	}
	registerEvents();

	if (nJump && m_stopAbajo) {
		nJump = false;
		mgravity = false;
		m_velocity.setY(0);
		jump();
	}

	if (mjumping) {
		if (m_velocity.getY() <= m_maxVelocity.getY() && aceleracionY == true && frictionY == false) {
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
		/*
		if (mjumping && frictionY == true) {
		m_position.setY(m_position.getY() + m_velocity.getY());
		}*/

		if (aceleracionY == false && frictionY == true) {
			frictionY = false;
			aceleracionY = true;
			mjumping = false;
			mgravity = true;
		}

		
	}

	


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
	if (mjumping) horizontal();
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

	if (m_position.getX() < 0) {
		stopX(0);
	}
	if (m_position.getX() > (Game::Instance()->get_ancho_ventana() - m_width)) {
		stopX(Game::Instance()->get_ancho_ventana() - m_width);
	}
	if (m_position.getY() < 0) {
		stopY(0);
	}
	if (m_position.getY() > (Game::Instance()->get_alto_ventana() - m_height)) {
		stopY(Game::Instance()->get_alto_ventana() - m_height);
	}
	m_lastStop.setX(m_position.getX());
	m_lastStop.setY(m_position.getY());

	TheCamera::Instance()->setPosition(m_lastStop);


};






void Player::horizontal() {
	if (ev_right_down || ev_right_up) {
		m_flip = 0;
		m_position.setX(m_position.getX() + m_velocity.getX());
	}
	if (ev_left_down || ev_left_up) {
		m_flip = 1;
		m_position.setX(m_position.getX() - m_velocity.getX());
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
	//m_velocity.setX(0);
}


void Player::aceleracion() {
	float tmp = 0;
	if (aceleracionY == true && frictionY == false) tmp = m_velocity.getX() + m_acceleration.getX() * 2;
	else tmp = m_velocity.getX() + m_acceleration.getX();
	m_velocity.setX(tmp);
	//m_velocity.setX(m_velocity.getX() + m_acceleration.getX());


}
void Player::friccion() {
	m_velocity.setX(m_velocity.getX() - m_friction.getX());


}



void Player::handleInput()
{
	Vector2D* target = InputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;
}

void Player::registerEvents() {

// eventos
ev_right_down = false, ev_left_down = false;
if (InputHandler::Instance()->isKeyDown(SDLK_RIGHT)) ev_right_down = true;
if (InputHandler::Instance()->isKeyDown(SDLK_LEFT)) ev_left_down = true;
if (InputHandler::Instance()->isKeyUp(SDLK_RIGHT)) ev_right_up = true;
if (InputHandler::Instance()->isKeyUp(SDLK_LEFT)) ev_left_up = true;
if (InputHandler::Instance()->isKeyDown(32) && mjumping == false) nJump = true;
}
/*
void Player::incrementAccelerationX() {
	float tmp = 0;
	if (aceleracionY == true && frictionY == false) tmp = m_velocity.getX() + m_acceleration.getX() * 2;
	else tmp = m_velocity.getX() + m_acceleration.getX();
	m_velocity.setX(tmp);
}

void Player::incrementFriction() {
	m_velocity.setX(m_velocity.getX() - m_friction.getX());
}
*/

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

void Player::clean() {

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