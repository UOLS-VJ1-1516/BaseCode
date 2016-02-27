#include "Player.h"
#include "TextureManager.h"
#include "game.h"
#include "string"
#include "PauseState.h"


int dir = 0;
int dreta = 1;
std::string texture;
int ultimaPos = 0;
bool colisionLeft = false;
bool colsionRight = false;
bool colisionBottom = false;
bool exit2 = false;
bool saltar = false;
bool saltoDerecha = false;
bool saltoIzquierda = false;
int entrada = 0;
Vector2D m_maxNegVelocity;
int m_positionMaxSalto;
bool gravedad = true;

Player::Player()
{
	
}

Player::~Player()
{
}

void Player::load(const LoaderParams* ppParams) {
	Player::pParams = ppParams;
	m_position.setX(pParams->getX());
	m_position.setY(pParams->getY());
	m_positionMaxSalto = 500;
	m_velocity.setX(0);
	m_velocity.setY(0);
	m_maxVelocity.setY(5);
	m_maxVelocity.setX(10);
	m_maxNegVelocity.setY(-10);
	m_maxNegVelocity.setX(-10);
	m_acceleration.setY(0);
	m_acceleration.setX(0);
	m_friction.setX(1);
	m_friction.setY(1);
	m_currentFrame = 0;
	m_currentRow = 1;
	width = pParams->getWidth();
	height = pParams->getHeight();
	colisionBottom = false;
}
void Player::draw() {
	SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;

	if(dir == 1){
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_HORIZONTAL);
	} 
	else {
		TextureManager::Instance()->drawFrame(pParams->getTextureID(), (int)m_position.getX(), (int)m_position.getY(), pParams->getWidth(), pParams->getHeight(), m_currentRow, m_currentFrame, Game::Instance()->getRender(), SDL_FLIP_NONE);
	}
}
void Player::update() {
	//m_velocity.setX(0);
	//m_acceleration.setX(0);
	//m_velocity.setY(0);
	//m_acceleration.setY(0);
	if (m_position.getY() > 1000) { //Si la nina cau per algun forat, acabem el programa
		//exit(-1);
		Game::Instance()->getStateMachine()->pushState(new PauseState());
	}
	if(!isCollisionWithTileBottom()&&gravedad==true) { //La gravetat s'aplica quan no hi ha colisió, no esta tocant el terra, i gravedad igual a true (deixem de saltar)
		printf("No Colision!!!");
		
		//m_acceleration.setY(0.00001);
		//m_velocity += m_acceleration;
		m_velocity.setY(-0.01);
		if (m_velocity.getY() > m_maxNegVelocity.getY()) {
			m_velocity.setY(m_maxNegVelocity.getY());
		}
		if ((m_position.getY() - m_velocity.getY() < 840)||(!isCollisionWithTileBottom())) { //Si no esta tocant al terra

			//Perque no caigui recte quan saltem de canto

			if (saltoDerecha == true) {
				m_velocity.setX(-3);
				saltoDerecha = false;
			}

			if (saltoIzquierda == true) { //Salto a la izquierda
				m_velocity.setX(3);
				saltoIzquierda = false;
			}

			m_position -= m_velocity;
		}
		else {
			m_position -= m_velocity;
			m_position.setY(840.00);
			colisionBottom = true;
			saltar = true;
		}
		
		//m_position.setY(m_position.getY() + 10);

		
		//exit2 = true;
	}
	else {
		//if (exit2 == true) {
			//if (m_position.getY() == 847.50 || m_position.getY() == 848.50) {
			//if (m_position.getY() == 850.00 || m_position.getY() == 853.00) {
			//if (m_position.getY() == 850.00 || m_position.getY() == 858.00) {
			//if (m_position.getY()<849.00) {
				//colisionBottom = true;
			//}
			/*while (isCollisionWithTile()) { //Per si encara hi ha colisio, passaria si en contes de passar una posicio passesim més de una, produit per la acceleració
				m_position.setY(m_position.getY() - 1);
			}*/
			/*if (isCollisionWithTile()) { //Per si encara hi ha colisio, passaria si en contes de passar una posicio passesim més de una, produit per la acceleració
				m_position.setY(840.00);
				colisionBottom = true;
			}
			/*
			if (isCollisionWithTile()) { //Per si encara hi ha colisio, passaria si en contes de passar una posicio passesim més de una, produit per la acceleració
				m_position.setY(840.00);
			}*/
			//exit2 = false;
			//saltar = true;
		//}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		{
			m_velocity.setY(0);
			m_acceleration.setY(0);
			if (colisionLeft != true) {
				if (isCollisionWithTile()) {
					printf("Colision!!!");
					colsionRight = true;
				}
			}
			if (colsionRight != true) {
				dir = 0;
				if (m_position.getX() < Game::Instance()->getGameWidth() - 30) {
					m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
					if (m_velocity.getX() <= 0) {
						m_velocity.setX(0);
					}
					m_acceleration.setX(1);
					m_velocity += m_acceleration;
					if (m_velocity.getX() > m_maxVelocity.getX()) {
						m_velocity.setX(m_maxVelocity.getX());
					}
					m_position += m_velocity;

					if (colisionLeft == true) {
						while (isCollisionWithTile()) { //Per si encara hi ha colisio, passaria si en contes de passar una posicio passesim més de una, produit per la acceleració
							m_position.setX(m_position.getX() + 1);
						}
					}

					colisionLeft = false;
				}
			}
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
			m_velocity.setY(0);
			m_acceleration.setY(0);
			if (colsionRight != true) {
				if (isCollisionWithTile()) {
					printf("Colision!!!");
					colisionLeft = true;
				}
			}
			if (colisionLeft != true) {
				if (m_position.getX() > 0) {
					dir = 1;
					m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
					if (m_velocity.getX() >= 0) {
						m_velocity.setX(-0.01);
					}
					m_acceleration.setX(-1);
					m_velocity += m_acceleration;
					if (m_velocity.getX() <= m_maxNegVelocity.getX()) {
						m_velocity.setX(-5);
					}
					m_position += m_velocity;
					if (colsionRight == true) { //Per si encara hi ha colisio, passaria si en contes de passar una posicio passesim més de una, produit per la acceleració
						while (isCollisionWithTile()) {
							m_position.setX(m_position.getX() - 1);
						}
					}
					colsionRight = false;
				}
			}
		}
		if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
			/*
			m_acceleration.setX(0.5);
			m_velocity += m_acceleration;
			if (m_velocity.getX() > m_maxVelocity.getX()) {
				m_velocity.setX(m_maxVelocity.getX());
			}
			m_position += m_velocity;
			*/
			

			m_velocity.setX(0);
			//m_acceleration.setX(0);
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) { //Salto a la derecha
				m_velocity.setX(3);
				saltoDerecha = true;
				saltoIzquierda = false;
			}
			
			if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) { //Salto a la izquierda
				m_velocity.setX(-3);
				saltoIzquierda = true;
				saltoDerecha = false;
			}

			m_acceleration.setY(-5);
			m_velocity += m_acceleration;
			m_position += m_velocity;

			if (m_position.getY() < m_positionMaxSalto) { //Limitamos la altura del salto
				//m_position.setY(m_positionMaxSalto);
				gravedad = true; //Lo ponemos a true para que entre en el if de la gravedad al llegar a la maxima altura del salto
				return;
			}

			colisionBottom = false;
			saltar = false;
			entrada = 0;
			colisionLeft = false;
			colsionRight = false;
			gravedad = false;
		}
		if (!InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE)) {
			gravedad = true; //Lo ponem a true para que entre en el if de la gravedad al llegar a la maxima altura del salto
		}
	}
}
void Player::clean() {
	//colisionBottom = false;
}

void Player::handleInput()
{
	Vector2D target = InputHandler::Instance()->getMousePosition();
	m_velocity = target - m_position;
	m_velocity /= 50;
}

