#include "Game.h"
#include "Player.h"
#include "TextureManager.h"
#include "InputHandler.h"


Player::Player() {  };
Player::~Player() {  };
bool quit = false;
int flag;
bool jump = false;
bool puedojump = false;
bool caigo = false;

int gravedad = 10;
bool aux;
int auxi = 0;
int velocidadSalto=30;

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
	m_acceleration.setX(0.1);
	m_acceleration.setY(30);
	m_maxvelocity.setX(3);   
	m_maxvelocity.setY(10);
	m_friction.setX(0.5);  //Ser� mi frenada
	m_friction.setY(5);

	m_velocitySalto.setY(0);
	m_accelerationSalto.setY(velocidadSalto);
	m_maxvelocitySalto.setY(-200);  //Hasta donde salto

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
	
	m_currentRow = 1;
	m_sprits = 1;
	int tecla = 0;
	InputHandler::Instance()->update();
	
		
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
			
				if (isCollisionWithRight()) {
					caigo = false;

				}
				if(!isCollisionWithRight()){
				
					if (!caigo) {

						//Compruebo velocidad maxima, si es menor puedo sumar aceleracion sino no.
						if (m_velocity.getX() < m_maxvelocity.getX()) {
							m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

						}
						m_position.setX(m_position.getX() + m_velocity.getX());
						if (!isCollisionWithDown() && jump) {
							puedojump = false;
							
							m_currentRow = 3;
							m_sprits = 6;
							if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
								m_velocitySalto.setY((m_velocitySalto.getY() - 3));
								m_position.setY(m_position.getY() - 3);
							}

							else {
								puedojump = true;
								jump = false;
							}
						}

						if (!isCollisionWithDown() && !jump) {
							caigo = true;
							m_currentRow = 3;
							m_sprits = 6;
							m_position.setY(m_position.getY() + gravedad-m_accelerationSalto.getY()); //Le meto gravedad
							if (m_velocity.getX() < m_maxvelocity.getX()) {
								m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

							}
							m_position.setX(m_position.getX() + m_velocity.getX());

						}
					}
					else{
						if (!isCollisionWithDown()) {
							m_currentRow = 3;
							m_sprits = 6;
							m_position.setY(m_position.getY() + gravedad); //Le meto gravedad
							if (m_velocity.getX() < m_maxvelocity.getX()) {
								m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

							}
							m_position.setX(m_position.getX() + m_velocity.getX());
						}
					/*	else {
							m_velocitySalto.setY(0);
							m_currentRow = 3;
							m_sprits = 6;
							if (m_velocity.getX() < m_maxvelocity.getX()) {
								m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

							}
							m_position.setX(m_position.getX() + m_velocity.getX());

						}*/
					}
				}
			break;




		//------LEFT---------------------------------
		case(2) :
		
			m_currentRow = 2;
			m_sprits = 6;
			m_flip = 2;
			flag = 2;

			if (isCollisionWithLeft()) {
				caigo = false;
				
			}
			if (!isCollisionWithLeft()) {
				if (!caigo) {
						if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
						m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
					}
					m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa
					if (!isCollisionWithDown() && jump) {
						m_currentRow = 3;
						m_sprits = 6;
						puedojump = false;
						if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
							m_velocitySalto.setY((m_velocitySalto.getY() - 3));
							m_position.setY(m_position.getY() - 3);
						}
						else {
							puedojump = true;
							jump = false;
						}
					}
					if (!isCollisionWithDown() && !jump) {
						caigo = true;
						m_currentRow = 3;
						m_sprits = 6;
						m_position.setY(m_position.getY() + gravedad - m_accelerationSalto.getY()); //Le meto gravedad
						if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
							m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
						}
						m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa

					}
				}
				else {
					if (!isCollisionWithDown()) {
						m_currentRow = 3;
						m_sprits = 6;
						m_position.setY(m_position.getY() + gravedad); //Le meto gravedad
						if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
							m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
						}
						m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa
					}
				/*	else {
						m_velocitySalto.setY(0);
						m_currentRow = 3;
						m_sprits = 6;
						if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
							m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
						}
						m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa
					}*/
					
				}
			}
			break;

			
		//------JUMP---------------------------------
		case(3) :
			if (puedojump) {
				m_currentRow = 3;
				m_sprits = 6;
				flag = 3;
				//---Encaro mu�eco
				switch (flag)
				{
				case (1) :
					m_flip = 1;
					break;
				case(2) :
					m_flip = 2;
					break;
				default:
					break;
				}


				if (isCollisionWithDown()) {
					
					jump = true;

					if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
						m_velocitySalto.setY((m_velocitySalto.getY() - m_accelerationSalto.getY()));
						m_position.setY(m_position.getY() + m_velocitySalto.getY());
					}
				}
				//Estoy en pleno salto
				else {
					if (jump) {
						
						if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
							
							m_velocitySalto.setY((m_velocitySalto.getY() - 10));
							m_position.setY(m_position.getY() - 10);
						}
						else {
							jump = false;
						}
					}
					if (!jump) {
						
						caigo = true;
						m_position.setY(m_position.getY() + gravedad); //Le meto gravedad
					}
		
				}
			}
			else {
				if (m_position.getY() < Game::Instance()->getAlto()) {
					m_sprits = 1;
					m_currentRow = 4;
					if(!isCollisionWithDown())m_position.setY(m_position.getY() + gravedad);
					else m_currentRow = 1;

				}
			}
			break;
		case(6) :
		//RightJump();
			break;
		case(7) :
		//	LeftJump();
			break;

		//----ESCAPE-----------------------
		case(5) :
			quit = true;
			break;

		//----------------No hay tecla pulsada------------------
		default:
			
			m_currentRow = 1;
			m_sprits = 1;
		//---------------------Seg�n de donde venga implemento un tipo de friccion
			switch (flag)
			{
				//---Friccion Derecha
			case (1) :
			
				m_flip = 1;
				//Si la velocidad no es 0 le resto la friccion y lo coloco en su posicion
				if (m_velocity.getX() > 0) {
						m_velocity.setX(m_velocity.getX() - m_friction.getX());
						m_position.setX(m_position.getX() + m_velocity.getX());
				
				}
				else {
						m_velocity.setX(0); 
						flag = 0;
				}
				break;

				//---Friccion Izquierda
			case(2) :
				
				m_flip = 2;
				if (m_velocity.getX() < 0) {		
					m_velocity.setX(m_velocity.getX() + m_friction.getX());
					m_position.setX(m_position.getX() + m_velocity.getX()); //La velocidad que llevo es negativa
				}
				else {
					m_velocity.setX(0); 
					flag = 0;
				}

				break;

				//---Friccion JUMP
			case(3) :
		
				break;

			default:
			
				break;
			}
	
			//m_position.setX(lastpositionok.getX());
			if (isCollisionWithDown()) {
				caigo = false;
				m_velocitySalto.setY(0);
				puedojump = true;
			}
			if (!isCollisionWithDown()) {
				puedojump = false;
				caigo = true;
				if (m_position.getY() < Game::Instance()->getAlto()) {
					m_sprits = 1;
					m_currentRow = 4;
					m_position.setY(m_position.getY() + gravedad);

				}
			

			}

			break;
		}
				m_currentFrame = (int)((SDL_GetTicks() / 100) % m_sprits);	


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

void Player::RightJump() {


	m_currentRow = 2;
	m_sprits = 6;
	m_flip = 1;
	flag = 1;

	if (isCollisionWithDown()) {

		jump = true;
	
		if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
			m_velocitySalto.setY((m_velocitySalto.getY() - m_accelerationSalto.getY()));
			m_position.setY(m_position.getY() + m_velocitySalto.getY());
		}
	}
	//Estoy en pleno salto
/*	else {
		if (jump) {

			if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
				m_velocitySalto.setY((m_velocitySalto.getY() - 3));
				m_position.setY(m_position.getY() - 3);
			}
			else {
				jump = false;
			}
		}
		if (!jump) {
			caigo = true;
			m_position.setY(m_position.getY() + gravedad); //Le meto gravedad
		}

	}*/


	if (isCollisionWithRight()) {
		caigo = false;

	}
	if (!isCollisionWithRight()) {

		if (!caigo) {

			//Compruebo velocidad maxima, si es menor puedo sumar aceleracion sino no.
			if (m_velocity.getX() < m_maxvelocity.getX()) {
				m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

			}
			m_position.setX(m_position.getX() + m_velocity.getX());
			if (!isCollisionWithDown() && jump) {
				puedojump = false;

				m_currentRow = 3;
				m_sprits = 6;
				if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
					m_velocitySalto.setY((m_velocitySalto.getY() - 3));
					m_position.setY(m_position.getY() - 3);
				}

				else {
					puedojump = true;
					jump = false;
				}
			}

			if (!isCollisionWithDown() && !jump) {
				caigo = true;
				m_currentRow = 3;
				m_sprits = 6;
				m_position.setY(m_position.getY() + gravedad - m_accelerationSalto.getY()); //Le meto gravedad
				if (m_velocity.getX() < m_maxvelocity.getX()) {
					m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

				}
				m_position.setX(m_position.getX() + m_velocity.getX());

			}
		}
		else {
			if (!isCollisionWithDown()) {
				m_currentRow = 3;
				m_sprits = 6;
				m_position.setY(m_position.getY() + gravedad); //Le meto gravedad
				if (m_velocity.getX() < m_maxvelocity.getX()) {
					m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

				}
				m_position.setX(m_position.getX() + m_velocity.getX());
			}
			/*else {
				m_velocitySalto.setY(0);
				m_currentRow = 3;
				m_sprits = 6;
				if (m_velocity.getX() < m_maxvelocity.getX()) {
					m_velocity.setX(m_velocity.getX() + m_acceleration.getX());

				}
				m_position.setX(m_position.getX() + m_velocity.getX());
				
			}*/
		}
	}

}
void Player::LeftJump() {

	m_currentRow = 2;
	m_sprits = 6;
	m_flip = 2;
	flag = 2;
	if (isCollisionWithDown()) {
	
		jump = true;

		if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
			m_velocitySalto.setY((m_velocitySalto.getY() - m_accelerationSalto.getY()));
			m_position.setY(m_position.getY() + m_velocitySalto.getY());
		}
	}
	if (isCollisionWithLeft()) {
		caigo = false;
	}
	if (!isCollisionWithLeft()) {
		if (!caigo) {
			if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
				m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
			}
			m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa
			if (!isCollisionWithDown() && jump) {
				m_currentRow = 3;
				m_sprits = 6;
				puedojump = false;
				if (m_velocitySalto.getY() > m_maxvelocitySalto.getY()) {
					m_velocitySalto.setY((m_velocitySalto.getY() - 3));
					m_position.setY(m_position.getY() - 3);
				}
				else {
					puedojump = true;
					jump = false;
				}
			}
			if (!isCollisionWithDown() && !jump) {
				caigo = true;
				m_currentRow = 3;
				m_sprits = 6;
				m_position.setY(m_position.getY() + gravedad - m_accelerationSalto.getY()); //Le meto gravedad
				if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
					m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
				}
				m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa

			}
		}
		else {
			if (!isCollisionWithDown()) {
				m_currentRow = 3;
				m_sprits = 6;
				m_position.setY(m_position.getY() + gravedad); //Le meto gravedad
				if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
					m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
				}
				m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa
			}
			/*else {
				m_velocitySalto.setY(0);
				m_currentRow = 3;
				m_sprits = 6;
				if (m_velocity.getX() > (m_maxvelocity.getX()*-1)) {
					m_velocity.setX((m_velocity.getX() + m_acceleration.getX()*-1));
				}
				m_position.setX(m_position.getX() + m_velocity.getX()); //aqui la velocidad ya ser� negativa
			}*/
		}
	}
}