#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "CollisionManager.h"
#include "OverState.h"
#include "PauseState.h"
#include <iostream>
#include "Camera.h"
#include <windows.h>


Player::Player() {  };
Player::~Player() {  };
bool quit = false;
int flag;
bool jump = false;
bool puedojump = false;
bool canPressJump = true;
bool caigo = false;
bool shouldJump = false;
int col = 1;
int gravedad = 10;
bool aux;
int auxi = 0;
bool entrado;

Vector2D lastpositionok;


void Player::load(const LoadPar * lPar)
{

	m_width = lPar->getWidth();
	m_height = lPar->getHeight();
	m_position.setX(lPar->getX());
	m_position.setY(lPar->getY());
	lastpositionok.setX(lPar->getX());
	lastpositionok.setY(lPar->getX());
	m_texid = lPar->getTextureID();
	m_sprits = lPar->getNumSprites();
	m_anchopantalla = Game::Instance()->getAncho();
	m_altopantalla = Game::Instance()->getAlto();
	m_currentFrame = 1;
	m_currentRow = 1;
	m_flip = 1;
	m_velocity.setX(0);  //Velocidad horizontal inicial
	m_velocity.setY(0);  //Velocidad verical inicial
	m_acceleration.setX(1);
	m_acceleration.setY(0);
	m_maxvelocity.setX(5);
	m_maxvelocity.setY(20);
	//m_friction.setX(5);  //Será mi frenada
	//m_friction.setY(5);
	gravedad = 10;
	m_velocitySalto.setY(0);
	m_accelerationSalto.setY(40);
	m_maxvelocitySalto.setY(-150);  //Hasta donde salto

};
void Player::draw()
{

	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Game::Instance()->GetRenderer(), m_flip);
}

void Player::draw(SDL_Renderer* Renderer) {
	TextureManager::Instance()->drawFrame(m_texid, m_position.getX(), m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, Renderer, m_flip);
}
bool exit() { return quit; }
//SDL_SCANCODE_ESCAPE    RIGHT LEFT UP

void Player::update() {
	Camera::Instance()->setPosition(m_position);
	m_currentRow = 1;
	m_sprits = 1;
	int tecla = 0;
	InputHandler::Instance()->update();
	CollisionObject::update(m_position);


	//CollisionManager::Instance->
	//	if (check()) printf("\nHAY COLISION.....\n");
	tecla = Miraquepulsa(); //Flag, 1->Right 2->Left 3->Space 4->Down, 5->Escape
							//printf("Pos X: %f \n Pos Y: %f \n", m_position.getX(), m_position.getY());

	switch (tecla)
	{
		//------RIGHT---------------------------------
	case(1) :
		m_currentRow = 2;
		m_sprits = 6;
		m_flip = 1;
		flag = 1;
		if (!isCollisionWithRight()&&isCollisionWithDown(this)) {

			if (m_velocity.getX() < m_maxvelocity.getX()) {
				m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

			}
			m_position.setX(m_position.getX() + m_velocity.getX());

		}
		break;

		//------LEFT---------------------------------
	case(2) :
		m_currentRow = 2;
		m_sprits = 6;
		m_flip = 2;
		flag = 2;
		if (!isCollisionWithLeft()&&isCollisionEnemyWithDown(this)) {
			if (m_velocity.getX() < (m_maxvelocity.getX())) {

				m_velocity.setX((m_velocity.getX() - m_acceleration.getX()));
			}
			m_position.setX(m_position.getX() + m_velocity.getX());
		}
		break;

		//------JUMP---------------------------------
	case(3) :
		
		if (canPressJump) {
			m_currentRow = 3;
			m_sprits = 6;
			flag = 3;
		
			printf("\nCaN PRESS OK");
			jump = true;
			canPressJump = false;
		}
		//Jump();
		break;

		//---JUMP + Direcciones
	case(6) :
		//RightJump();
		break;

	case(7) :
		//LeftJump();
		break;

		//----ESCAPE-----------------------
	case(5) :
		quit = true;
		break;

		//----------------No hay tecla pulsada------------------
	default:
		m_currentRow = 1;
		m_sprits = 1;
		//---------------------Según de donde venga implemento un tipo de friccion
		switch (flag)
		{
			//---Friccion Derecha
		case (1) :

			m_flip = 1;
			//Si la velocidad no es 0 le resto la friccion y lo coloco en su posicion
			/*if (m_velocity.getX() > 0) {
				m_velocity.setX(m_velocity.getX() - m_friction.getX());
				m_position.setX(m_position.getX() + m_velocity.getX());

			}*/
			//else {
				m_velocity.setX(0);
				flag = 0;
			//}
			break;

			//---Friccion Izquierda
		case(2) :

			m_flip = 2;
			/*if (m_velocity.getX() < 0) {
				m_velocity.setX(m_velocity.getX() + m_friction.getX());
				m_position.setX(m_position.getX() + m_velocity.getX()); //La velocidad que llevo es negativa
			}
			else {*/
				m_velocity.setX(0);
				flag = 0;
			//}

			break;

			//---Friccion JUMP
		case(3) :

			break;

		default:

			break;
		}

		//m_position.setX(lastpositionok.getX());
		if (isCollisionWithDown(this)) {
			
			if (jump) {
					m_position.setY(m_position.getY() - 10);
					shouldJump = true;
			}

		//	shouldJump = false;
			//jump = false;
			
		}
		if (!isCollisionWithDown(this)) {	

			if (shouldJump) {
				//----Estoy "subiendo"
				if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
					m_velocitySalto.setY((m_velocitySalto.getY() - 30));
					m_position.setY(m_position.getY()-30);
				}
				//----Estoy bajando
				else {
					m_sprits = 1;
					m_currentRow = 4;
					m_position.setY(m_position.getY() + 10);
					if (isCollisionWithDown(this)) {
						jump = false;
						shouldJump = false;
						canPressJump = true;
						printf("\nBIENN\n");
						
					}
					
				}

			}
			else {
				if (m_position.getY() < Game::Instance()->getAlto() && !shouldJump) {
					m_sprits = 1;
					m_currentRow = 4;
					m_position.setY(m_position.getY() + gravedad);

				}
			}
		}

		break;
	}
	m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);	if (CollisionManager::YColision()) {		printf("\nENTROOOO en col 1 y col vale: %d", col);
		m_currentRow = 5;
		m_currentFrame = 0;		if (col == 2) {
			printf("\n ENTROOOO en col 2 y col vale: %d", col);
			Sleep(1000);
			Game::Instance()->getGameStateMachine()->pushState(new OverState());		}		col++;	}	else {		col = 1;		/*if (CollisionManager::YColision() && col == 1 && (!entrado)) {
		entrado = true;
		printf("\nENTROOOO en col 1");
		m_currentRow = 5;
		m_currentFrame = 0;
		//col++;
		}		if (CollisionManager::YColision() &&  (entrado)) {

		Sleep(1000);
		printf("\nENTROOOO en col 2");
		entrado = false;
		Game::Instance()->getGameStateMachine()->pushState(new OverState());


		//		CollisionManager::Instance()->setY(false);

		}*/
		if (m_position.getY() > m_altopantalla - 60) {

			m_currentRow = 5;
			m_currentFrame = 0;
		}
		if (m_position.getY() > m_altopantalla - 30) {

			m_currentRow = 5;
			m_currentFrame = 1;
		}
		if (m_position.getY() > m_altopantalla - 20) {

			m_currentRow = 5;
			m_currentFrame = 2;
		}

		if (m_position.getY() > m_altopantalla - 10) {
			m_currentRow = 5;
			m_currentFrame = 3;
			Sleep(1000);

			Game::Instance()->getGameStateMachine()->pushState(new OverState());
		}
	}

	//------------------Netejo pantalla--------> para que salga por el otro lado eje vertical, limitando eje horizontal
	/*if (m_position.getX() > m_anchopantalla - 175) { m_position.setX(m_anchopantalla - 175); }
	if (m_position.getX() < 0) { m_position.setX(0); }
	if (m_position.getY() > m_altopantalla + 80) { m_position.setY(0 - 15); }
	if (m_position.getY() < 0 - 150) { m_position.setY(m_altopantalla + 15); }*/
}


void Player::clean() {}


int Player::Miraquepulsa() {
	bool aux;
	int tecla = 0;
	aux = InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT);
	if (aux) tecla = 1;
	aux = InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT);
	if (aux) tecla = 2;
	aux = InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE);
	if (aux) tecla = 3;
	aux = InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE);
	if (aux) tecla = 5;
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		tecla = 6;
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		tecla = 7;
	}

	return tecla;

}
